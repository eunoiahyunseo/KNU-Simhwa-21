import React from "react";
import Pagination from "../../components/posts/Pagination";
import { useSelector } from "react-redux";
import { useParams, useLocation } from "react-router-dom";
import qs from "qs";

const PaginationContainer = () => {
  const { username } = useParams();
  const location = useLocation();
  const { lastPage, posts, loading } = useSelector(
    ({ posts, loading }) => ({
      lastPage: posts.lastPage,
      posts: posts.posts,
      loading: loading["posts/LIST_POSTS"],
    })
  );

  if (!posts || loading) return null;

  // page가 만약에 안들어 온다면 어떻게하지 => defualt 1
  // username, tag는 없어도 되는 선택적인 값인데 page는 필수이기 때문
  const { tag, page = 1 } = qs.parse(location.search, {
    ignoreQueryPrefix: true,
  });

  return (
    <Pagination
      page={parseInt(page, 10)}
      lastPage={lastPage}
      tag={tag}
      username={username}
    />
  );
};

export default PaginationContainer;
