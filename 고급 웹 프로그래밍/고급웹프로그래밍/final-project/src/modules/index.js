import { combineReducers } from "redux";
import auth, { authSaga } from "./auth";
import loading from "./loading";
import user, { userSaga } from "./user";
import write, { writeSaga } from "./write";
import post, { postSaga } from "./post";
import posts, { postsSaga } from "./posts";
import profile, { profileSaga } from "./profile";

import { all } from "redux-saga/effects";

const rootReducers = combineReducers({
  auth,
  loading,
  user,
  write,
  post,
  posts,
  profile,
});

// all은 그냥 등록하는 것일 뿐이다.
export function* rootSaga() {
  yield all([
    authSaga(),
    userSaga(),
    writeSaga(),
    postSaga(),
    postsSaga(),
    profileSaga(),
  ]);
}

export default rootReducers;
