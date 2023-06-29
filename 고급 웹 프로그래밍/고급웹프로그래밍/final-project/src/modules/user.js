// import { createAction, handleActions } from "redux-actions";
// import { call, takeLatest } from "redux-saga/effects";

// 사가를 만들어 주어야 합니다.

// delay >> 설정된 시간 이후에 resolve하는 Promise객체를 리턴

// put >> 특정 액션을 dispatch하도록 합니다.
// put({type: 'INCREMENT'}) >> INCREMENT action을 dispath하도록 합니다.

// takeEvery >> 들어오는 모든 액션에 대해 특정 작업을 처리해 줍니다.
// takeEvery(INCREASE_ASYNC, increaseSaga) >> 들어오는 모든 INCRESE_ASYNC액션에 대해서 increaseSaga함수를 실행합니다.

// takeLatest는 기존에 처리 중이던 작업이 있다면 취소 처리하고 가장 마지막으로 실행된 작업만 실행한다는 특징이 있습니다.

// call >> 함수의 첫 번째 파라미터는 함수, 나머지 파라미터는 해당 함수에 넣을 인수가 됩니다.
// call(delay, 1000) >> delay(1000)함수를 call함수를 사용해서 이렇게 쓸 수도 있습니다.

// all >> 제너레이터 함수를 배열의 형태로 인자로 넣으면, 제너레이터 함수들이 병행적으로 실행됩니다.
// 그리고 전부 resolve될 때까지 기다립니다. Promise.all과 비슷합니다.
// yield.all([testSaga1(), testSaga2()]) >> testSaga1()과 testSaga2()가 동시에 실행되고, 모두 resolve될 때까지 기다립니다.

import { createAction, handleActions } from "redux-actions";
import createRequestSaga, {
  createRequestActionTypes,
} from "../lib/createRequestSaga";
import { takeLatest, call } from "redux-saga/effects";
import * as authAPI from "../lib/api/auth";

const TEMP_SET_USER = "user/TEMP_SET_USER";
// profile리덕스에 있는 값으로 user의 값을 바꿔주어야 한다.
const SYNC_WITH_PROFILE = "user/SYNC_WITH_PROFILE";
// 회원 정보 확인
const [CHECK, CHECK_SUCCESS, CHECK_FAILURE] =
  createRequestActionTypes("user/CHECK");

const LOGOUT = "user/LOGOUT";

export const syncProfile = createAction(
  SYNC_WITH_PROFILE,
  (info) => info
);
export const tempSetUser = createAction(
  TEMP_SET_USER,
  (user) => user
);
export const check = createAction(CHECK);
export const logout = createAction(LOGOUT);

const checkSaga = createRequestSaga(CHECK, authAPI.check);
function checkFailureSaga() {
  try {
    localStorage.removeItem("user");
  } catch (e) {
    console.log("localStorage is not working");
  }
}
// 여기에서는 logoutAPI를 불러서 cookie를 없애고
// localStorage에 있는 user의 값을 삭제해야 한다.
function* logoutSaga() {
  try {
    yield call(authAPI.logout);
    localStorage.removeItem("user");
  } catch (e) {
    console.log(e);
  }
}

export function* userSaga() {
  yield takeLatest(CHECK, checkSaga);
  yield takeLatest(CHECK_FAILURE, checkFailureSaga);
  yield takeLatest(LOGOUT, logoutSaga);
}

const initialState = {
  user: null,
  checkError: null,
};

const user = handleActions(
  {
    [TEMP_SET_USER]: (state, { payload: user }) => ({
      ...state,
      user,
    }),
    [CHECK_SUCCESS]: (state, { payload: user }) => ({
      ...state,
      user,
      checkError: null,
    }),
    [CHECK_FAILURE]: (state, { payload: error }) => ({
      ...state,
      user: null,
      checkError: error,
    }),
    [LOGOUT]: (state) => ({
      ...state,
      user: null,
    }),
    [SYNC_WITH_PROFILE]: (
      state,
      { payload: { email, username } }
    ) => ({
      ...state,
      user: {
        ...state.user,
        email,
        username,
      },
    }),
  },
  initialState
);

export default user;
