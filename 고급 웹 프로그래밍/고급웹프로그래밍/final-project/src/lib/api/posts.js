import client from "./client";
import qs from "qs";

export const writePost = ({ title, body, tags, capacity }) =>
  client.post("/api/posts", { title, body, tags, capacity });

export const readPost = (id) => client.get(`/api/posts/${id}`);

export const listPosts = ({ page, username, tag }) => {
  const queryString = qs.stringify({
    page,
    username,
    tag,
  });
  return client.get(`/api/posts?${queryString}`);
};

export const updatePost = ({
  id,
  title,
  body,
  tags,
  capacity,
}) =>
  client.patch(`/api/posts/${id}`, {
    title,
    body,
    tags,
    capacity,
  });

export const removePost = (id) =>
  client.delete(`/api/posts/${id}`);

export const likePost = ({ postId, userId }) =>
  client.patch(`/api/posts/${postId}/${userId}`);
