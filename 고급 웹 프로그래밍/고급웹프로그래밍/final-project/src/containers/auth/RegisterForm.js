import React, { useEffect, useState } from "react";
import { useDispatch, useSelector } from "react-redux";
import {
  changeField,
  initializeForm,
  register,
} from "../../modules/auth";
import AuthForm from "../../components/auth/AuthForm";
import { check } from "../../modules/user";
import { useNavigate } from "react-router-dom";

const RegisterForm = () => {
  const [error, setError] = useState(null);

  const dispatch = useDispatch();
  const navigate = useNavigate();
  const { form, auth, authError, user } = useSelector(
    ({
      auth: { register, auth, authError },
      user: { user },
    }) => ({
      form: register,
      auth,
      authError,
      user,
    })
  );

  // 인풋을 변경했을 때 반응하는 핸들러
  const onChange = (e) => {
    const {
      target: { value, name },
    } = e;

    dispatch(
      changeField({
        form: "register",
        key: name,
        value,
      })
    );
  };

  // 폼 등록 이벤트 헨들러
  const onSubmit = (e) => {
    e.preventDefault();
    const { email, password, passwordConfirm } = form;
    if ([email, password, passwordConfirm].includes("")) {
      setError("빈 칸을 모두 입력해 주세요");
      return;
    }

    if (password !== passwordConfirm) {
      setError("비밀번호가 일치하지 않습니다.");
      dispatch(
        changeField({
          form: "register",
          key: "password",
          value: "",
        })
      );
      dispatch(
        changeField({
          form: "register",
          key: "passwordConfirm",
          value: "",
        })
      );
      return;
    }
    dispatch(register({ email, password }));
  };

  // 컴포넌트가 처음 렌더링될 떄 form을 초기화 하는 작업이 있어야 함.
  useEffect(() => {
    dispatch(initializeForm("register"));
  }, [dispatch]);

  // 회원가입 버튼을 눌렀을 때 처리할 useEffect
  useEffect(() => {
    // 이미 계정명이 존재하면 409 (Conflict가 발생한다)

    if (authError) {
      if (authError.response.status === 409) {
        setError("이미 존재하는 계정명입니다.");
        return;
      }

      // 기타 이유라면
      setError("회원가입 실패");
      return;
    }

    if (auth) {
      console.log("회원가입 성공");
      console.log(auth);
      dispatch(check());
    }
  }, [dispatch, auth, authError]);

  useEffect(() => {
    if (user) {
      navigate("/");
      try {
        localStorage.setItem("user", JSON.stringify(user));
      } catch (e) {
        console.log("localStorage is not working");
      }
    }
  });
  return (
    <AuthForm
      type="register"
      onChange={onChange}
      onSubmit={onSubmit}
      form={form}
      error={error}
    />
  );
};

export default RegisterForm;
