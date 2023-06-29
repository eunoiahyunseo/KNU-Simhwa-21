import React from "react";
import NavBarContainer from "../containers/common/NavBarContainer";
import HeaderContainer from "../containers/common/HeaderContainer";
import PostListContainer from "../containers/post/PostListContainer";
import PaginationContainer from "../containers/posts/PaginationContainer";
import Footer from "../components/common/Footer";

const PostListPage = () => {
  return (
    <>
      <NavBarContainer />
      <HeaderContainer />
      <PostListContainer />
      <PaginationContainer />
      <Footer />
    </>
  );
};

export default PostListPage;
