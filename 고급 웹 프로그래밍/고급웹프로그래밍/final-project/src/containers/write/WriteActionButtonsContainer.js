import React, { useEffect } from "react";
import WriteActionButtons from "../../components/write/WriteActionButtons";
import { useSelector, useDispatch } from "react-redux";
import { writePost, updatePost } from "../../modules/write";
import { debounce } from "lodash";

const WriteActionButtonsContainer = ({ navigate }) => {
  const dispatch = useDispatch();
  const {
    title,
    body,
    tags,
    post,
    postError,
    originalPostId,
    capacity,
  } = useSelector(
    ({
      write: {
        title,
        body,
        tags,
        post,
        postError,
        originalPostId,
        capacity,
      },
    }) => ({
      title,
      body,
      tags,
      post,
      postError,
      originalPostId,
      capacity,
    })
  );

  const onPublish = debounce(() => {
    if (title === "" || body === "" || capacity === "") {
      alert("제목또는 본문 또는 모집인원을 비워서는 안됩니다.");
      return;
    }

    if (capacity > 20 || capacity < 2) {
      alert("스터디 모집 인원은 최소 2명 최대 20명입니다.");
      return;
    }

    if (originalPostId) {
      dispatch(
        // originalPostId의 포스트를 새 데이터로 업데이트 시켜줘야 한다.
        updatePost({
          title,
          body,
          tags,
          capacity,
          id: originalPostId,
        })
      );
      return;
    }
    dispatch(
      writePost({
        title,
        body,
        tags,
        capacity,
      })
    );
  }, 700);

  const onCancel = () => {
    navigate(-1);
  };

  // 만약 포스트가 등록 되었다면 post가 생성될 것이다
  useEffect(() => {
    if (post) {
      const { _id, user } = post;
      navigate(`/@${user.username}/${_id}`);
    }
    if (postError) {
      console.error(postError);
    }
  }, [navigate, post, postError]);

  return (
    <WriteActionButtons
      onPublish={onPublish}
      onCancel={onCancel}
      isEdit={!!originalPostId}
    />
  );
};

export default WriteActionButtonsContainer;
