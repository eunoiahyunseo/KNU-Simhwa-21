import { createAction, handleActions } from "redux-actions";
import createRequestSaga, {
  createRequestActionTypes,
} from "../lib/createRequestSaga";
import * as postAPI from "../lib/api/posts";
import { takeLatest } from "redux-saga/effects";

const [LIST_POSTS, LIST_POSTS_SUCCESS, LIST_POSTS_FAILURE] =
  createRequestActionTypes("posts/LIST_POSTS");

export const listPosts = createAction(
  LIST_POSTS,
  ({ tag, username, page }) => ({
    tag,
    username,
    page,
  })
);

const listPostsSaga = createRequestSaga(
  LIST_POSTS,
  postAPI.listPosts
);

export function* postsSaga() {
  yield takeLatest(LIST_POSTS, listPostsSaga);
}

const initialState = {
  posts: null,
  error: null,
  lastPage: 1,
};

const posts = handleActions(
  {
    [LIST_POSTS_SUCCESS]: (
      state,
      { payload: posts, meta: response }
    ) => ({
      ...state,
      posts,
      lastPage: +response.headers["last-page"],
    }),
    [LIST_POSTS_FAILURE]: (state, { payload: error }) => ({
      ...state,
      error,
    }),
  },
  initialState
);

export default posts;
