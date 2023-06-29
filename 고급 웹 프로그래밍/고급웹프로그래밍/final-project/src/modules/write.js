import { createAction, handleActions } from "redux-actions";
import createRequestSaga, {
  createRequestActionTypes,
} from "../lib/createRequestSaga";
import { takeLatest } from "redux-saga/effects";
import * as postAPI from "../lib/api/posts";

// 글쓰기 상태를 관리하는 리덕스
const INITIALIZE = "write/INITIALIZE"; // 모든 내용을 초기화 하는 액션
const CHANGE_FIELD = "write/CHANGE_FIELD"; // 특정 key값을 바꿀 수 있게 하는 액션

// 이는 현재 보고 있는 포스트 정보를 write모듈에서 관리하는 상태에 넣습니다.
const SET_ORIGINAL_POST = "write/SET_ORIGINAL_POST";

const [WRITE_POST, WRITE_POST_SUCCESS, WRITE_POST_FAILURE] =
  createRequestActionTypes("write/WRITE_POST");

const [UPDATE_POST, UPDATE_POST_SUCCESS, UPDATE_POST_FAILURE] =
  createRequestActionTypes("write/UPDATE_POST");

export const initialize = createAction(INITIALIZE);
export const changeField = createAction(
  CHANGE_FIELD,
  ({ key, value }) => ({
    key,
    value,
  })
);

export const setOriginalPost = createAction(
  SET_ORIGINAL_POST,
  (post) => post
);

// 글쓰기 액션
export const writePost = createAction(
  WRITE_POST,
  ({ title, body, tags, capacity }) => ({
    title,
    body,
    tags,
    capacity,
  })
);

// 업데이트 액션
export const updatePost = createAction(
  UPDATE_POST,
  ({ id, title, body, tags, capacity }) => ({
    id,
    title,
    body,
    tags,
    capacity,
  })
);

// 글쓰기 사가 생성
const writePostSaga = createRequestSaga(
  WRITE_POST,
  postAPI.writePost
);

const updatePostSaga = createRequestSaga(
  UPDATE_POST,
  postAPI.updatePost
);

export function* writeSaga() {
  yield takeLatest(WRITE_POST, writePostSaga);
  yield takeLatest(UPDATE_POST, updatePostSaga);
}

const initialState = {
  title: "",
  body: "",
  capacity: "",
  tags: [],
  post: null,
  postError: null,
  originalPostId: null,
};

const write = handleActions(
  {
    [INITIALIZE]: (_) => initialState,
    [CHANGE_FIELD]: (state, { payload: { key, value } }) => ({
      ...state,
      [key]: value,
    }),
    [WRITE_POST]: (state) => ({
      ...state,
      // post와 postError를 초기화 해야 한다.
      post: null,
      postError: null,
    }),
    // 포스트 작성 성공
    [WRITE_POST_SUCCESS]: (state, { payload: post }) => ({
      ...state,
      post,
    }),
    // 포스트 작성 실패
    [WRITE_POST_FAILURE]: (state, { payload: postError }) => ({
      ...state,
      postError,
    }),
    [SET_ORIGINAL_POST]: (
      state,
      { payload: { title, body, tags, _id, capacity } }
    ) => ({
      ...state,
      title,
      body,
      tags,
      capacity,
      originalPostId: _id,
    }),
    [UPDATE_POST_SUCCESS]: (state, { payload: post }) => ({
      ...state,
      post,
    }),
    [UPDATE_POST_FAILURE]: (state, { payload: postError }) => ({
      ...state,
      postError,
    }),
  },
  initialState
);

export default write;
