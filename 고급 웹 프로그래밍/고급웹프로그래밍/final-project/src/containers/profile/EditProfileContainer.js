import React, { useEffect, useCallback, useState } from "react";
import styled from "styled-components";
import { useDispatch, useSelector } from "react-redux";
import EditProfile from "../../components/profile/EditProfile";
import {
  changeField,
  updateProfile,
} from "../../modules/profile";
import { syncProfile } from "../../modules/user";
import { useNavigate } from "react-router-dom";

const EditProfileContainer = () => {
  const [error, setError] = useState("");
  const navigator = useNavigate();
  const dispatch = useDispatch();
  const { user, profile } = useSelector(
    ({ user: { user }, profile }) => ({
      user,
      profile,
    })
  );

  const onChangeField = useCallback(
    (payload) => dispatch(changeField(payload)),
    [dispatch]
  );

  const onConfirm = () => {
    // 이렇게 한 다음에 값이 바뀌면, user의 값을 profile의 값과 동기화 시켜주어야 한다.
    if (profile.username === "") {
      setError("username칸을 채워주세요.");
      return;
    }

    if (profile.username === user.username) {
      setError("username을 변경해주세요.");
      return;
    }

    dispatch(updateProfile({ ...profile, _id: user._id }));
    dispatch(syncProfile(profile));
    setError("");
  };

  const onBackClick = () => {
    navigator("/");
  };

  // 오류의 종류
  // 1. username을 비워놓은 경우

  useEffect(() => {}, []);

  return (
    <EditProfile
      user={user}
      onChangeField={onChangeField}
      profile={profile}
      onConfirm={onConfirm}
      onBackClick={onBackClick}
      errorMessage={error}
    />
  );
};

export default EditProfileContainer;
