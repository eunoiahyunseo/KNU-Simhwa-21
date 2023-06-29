import React, { useEffect, useCallback } from "react";
import Editor from "../../components/write/Editor";
import { useSelector, useDispatch } from "react-redux";
import { changeField, initialize } from "../../modules/write";

const EditorContainer = () => {
  const dispatch = useDispatch();
  let { title, body, capacity } = useSelector(
    ({ write: { title, body, capacity } }) => ({
      title,
      body,
      capacity,
    })
  );

  const onChangeField = useCallback(
    (payload) => dispatch(changeField(payload)),
    [dispatch]
  );

  // 만약에 화면에서 언마운트 된다면 이를 초기화 해줘야 한다.
  useEffect(() => {
    dispatch(changeField({ key: "capacity", value: "2" }));
    return () => {
      dispatch(initialize());
    };
  }, [dispatch]);

  return (
    <Editor
      onChangeField={onChangeField}
      title={title}
      body={body}
      capacity={capacity}
    />
  );
};

export default EditorContainer;
