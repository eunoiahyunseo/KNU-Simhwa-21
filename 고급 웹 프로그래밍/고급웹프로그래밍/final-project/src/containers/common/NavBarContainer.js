import React, { useState } from "react";
import NavBar from "../../components/common/NavBar";
import { useDispatch, useSelector } from "react-redux";
import { logout } from "../../modules/user";

const NavBarContainer = () => {
  const dispatch = useDispatch();
  const { user } = useSelector(({ user: { user } }) => ({
    user,
  }));

  const onLogout = () => {
    dispatch(logout());
  };

  const [navItemList, setNavItemList] = useState([
    "HomePage",
    "EditProfile",
    "MyPost",
    "Login",
    "Register",
    "Logout",
  ]);
  return (
    <NavBar
      navItemList={navItemList}
      isLoggedIn={!!user}
      onLogout={onLogout}
      user={user}
    />
  );
};

export default NavBarContainer;
