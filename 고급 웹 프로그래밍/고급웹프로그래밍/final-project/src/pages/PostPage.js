import React from "react";
import PostViewerContainer from "../containers/post/PostViewerContainer";
import HeaderContainer from "../containers/common/HeaderContainer";
import NavBarContainer from "../containers/common/NavBarContainer";

const PostPage = () => {
  return (
    <>
      <NavBarContainer />
      <HeaderContainer />
      <PostViewerContainer />
    </>
  );
};

export default PostPage;
