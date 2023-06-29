import React from "react";
import { useSelector, useDispatch } from "react-redux";
import Header from "../../components/common/Header";
import { logout } from "../../modules/user";
import { useNavigate } from "react-router-dom";

const HeaderContainer = () => {
  const navigate = useNavigate();

  const { user } = useSelector(({ user: { user } }) => ({
    user,
  }));
  const dispatch = useDispatch();
  const onLogout = () => {
    dispatch(logout());
    navigate("/");
  };
  return <Header user={user} onLogout={onLogout} />;
};

export default HeaderContainer;
