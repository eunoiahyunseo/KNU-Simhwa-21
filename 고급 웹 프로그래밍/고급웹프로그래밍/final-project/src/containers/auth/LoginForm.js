import React, { useEffect, useState } from "react";
import { useDispatch, useSelector } from "react-redux";
import { changeField, initializeForm } from "../../modules/auth";
import AuthForm from "../../components/auth/AuthForm";
import { useNavigate } from "react-router-dom";
import { login } from "../../modules/auth";
import { check } from "../../modules/user";

const LoginForm = () => {
  const [error, setError] = useState(null);
  const dispatch = useDispatch();
  const navigate = useNavigate();
  const { form, auth, authError, user } = useSelector(
    ({ auth: { login, auth, authError }, user: { user } }) => ({
      form: login,
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
        form: "login",
        key: name,
        value,
      })
    );
  };

  // 폼 등록 이벤트 헨들러
  const onSubmit = (e) => {
    e.preventDefault();
    const { email, password } = form;
    dispatch(login({ email, password }));
  };

  // 컴포넌트가 처음 렌더링될 떄 form을 초기화 하는 작업이 있어야 함.
  useEffect(() => {
    dispatch(initializeForm("login"));
  }, [dispatch]);

  // 회원가입 버튼을 눌렀을 때 처리할 useEffect
  useEffect(() => {
    if (authError) {
      console.log("오류 발생");
      console.log(authError);
      setError("로그인 실패");
      return;
    }

    if (auth) {
      console.log("로그인 성공");
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
      type="login"
      onChange={onChange}
      onSubmit={onSubmit}
      form={form}
      error={error}
    />
  );
};

export default LoginForm;
