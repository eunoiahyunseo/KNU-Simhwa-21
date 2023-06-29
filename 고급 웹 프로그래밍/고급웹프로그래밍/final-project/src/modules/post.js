import { createAction, handleActions } from "redux-actions";
import createRequestSaga, {
  createRequestActionTypes,
} from "../lib/createRequestSaga";
import { takeLatest } from "redux-saga/effects";
import * as postAPI from "../lib/api/posts";
import * as authAPI from "../lib/api/auth";

const [READ_POST, READ_POST_SUCCESS, READ_POST_FAILURE] =
  createRequestActionTypes("post/READ_POST");

const UNLOAD_POST = "post/UNLOAD_POST";

// 스터디 ( POST )에 참여하는 액션
const [JOIN_POST, JOIN_POST_SUCCESS, JOIN_POST_FAILURE] =
  createRequestActionTypes("post/JOIN_POST");
const [
  CHECK_LIKE_USER,
  CHECK_LIKE_USER_SUCCESS,
  CHECK_LIKE_USER_FAILURE,
] = createRequestActionTypes("auth/CHECK_LIKE_USER");

export const readPost = createAction(READ_POST, (id) => id);
export const unloadPost = createAction(UNLOAD_POST);

export const check_like_user = createAction(
  CHECK_LIKE_USER,
  (userInfo) => userInfo
);

/**
 * idInfo는 {postId, userId}이런 형태로 주어져야 한다.
 */
export const joinPost = createAction(
  JOIN_POST,
  (idInfo) => idInfo
);

const readPostSaga = createRequestSaga(
  READ_POST,
  postAPI.readPost
);

const joinPostSaga = createRequestSaga(
  JOIN_POST,
  postAPI.likePost
);

const checkLikeUserSaga = createRequestSaga(
  CHECK_LIKE_USER,
  authAPI.check_like_user
);

export function* postSaga() {
  yield takeLatest(READ_POST, readPostSaga);
  yield takeLatest(JOIN_POST, joinPostSaga);
  yield takeLatest(CHECK_LIKE_USER, checkLikeUserSaga);
}

const initialState = {
  post: null,
  error: null,
  like_user: [],
  like_user_error: null,
};

const post = handleActions(
  {
    [READ_POST_SUCCESS]: (state, { payload: post }) => ({
      ...state,
      post,
    }),
    [READ_POST_FAILURE]: (state, { payload: error }) => ({
      ...state,
      error,
    }),
    [JOIN_POST_SUCCESS]: (state, { payload: post }) => ({
      ...state,
      post,
    }),
    [JOIN_POST_FAILURE]: (state, { payload: error }) => ({
      ...state,
      error,
    }),
    [UNLOAD_POST]: () => initialState,
    [CHECK_LIKE_USER_SUCCESS]: (
      state,
      { payload: like_user }
    ) => ({
      ...state,
      like_user,
    }),
    [CHECK_LIKE_USER_FAILURE]: (state, { payload: error }) => ({
      ...state,
      like_user_error: error,
    }),
  },
  initialState
);

export default post;
