import React, { useEffect, useCallback } from "react";
import qs from "qs";
import { useDispatch, useSelector } from "react-redux";
import PostList from "../../components/post/PostList";
import { listPosts } from "../../modules/posts";
import { useParams, useLocation } from "react-router-dom";
import { useNavigate } from "react-router-dom";

const PostListContainer = () => {
  const dispatch = useDispatch();
  const location = useLocation();
  const { username } = useParams();
  const navigate = useNavigate();

  const { posts, error, loading, user } = useSelector(
    ({ posts: { posts, error }, loading, user: { user } }) => ({
      posts,
      error,
      loading: loading["posts/LIST_POSTS"],
      user,
    })
  );

  useEffect(() => {
    const { tag, page, username } = qs.parse(location.search, {
      ignoreQueryPrefix: true,
    });
    dispatch(listPosts({ tag, page, username }));
  }, [dispatch, username, location.search]);

  const onPostClick = useCallback(
    (username, _id) => {
      navigate(`/@${username}/${_id}`);
    },
    [navigate]
  );

  return (
    <PostList
      loading={loading}
      error={error}
      posts={posts}
      showWriteButton={user}
      user={user}
      onPostClick={onPostClick}
    />
  );
};

export default PostListContainer;
