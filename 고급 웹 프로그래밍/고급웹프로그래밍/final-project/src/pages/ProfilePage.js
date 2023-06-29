import React from "react";
import NavBarContainer from "../containers/common/NavBarContainer";
import HeaderContainer from "../containers/common/HeaderContainer";
import EditProfileContainer from "../containers/profile/EditProfileContainer";

const ProfilePage = () => {
  return (
    <>
      <NavBarContainer />
      <HeaderContainer />
      <EditProfileContainer />
    </>
  );
};

export default ProfilePage;
