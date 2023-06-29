import { createAction, handleActions } from "redux-actions";
import produce from "immer";
import createRequestSaga, {
  createRequestActionTypes,
} from "../lib/createRequestSaga";
import { takeLatest } from "redux-saga/effects";
import * as authAPI from "../lib/api/auth";

// 회원의 로그인 인증과 관련된 리덕스
const CHANGE_FIELD = "auth/CHANGE_FIELD";
const INITIALIZE_FORM = "auth/INITIALIZE_FORM";

const [REGISTER, REGISTER_SUCCESS, REGISTER_FAILURE] =
  createRequestActionTypes("auth/REGISTER");

const [LOGIN, LOGIN_SUCCESS, LOGIN_FAILURE] =
  createRequestActionTypes("auth/LOGIN");

export const changeField = createAction(
  CHANGE_FIELD,
  ({ form, key, value }) => ({
    form, // register || login
    key, // username, password, passwordConfirm
    value, // 실제로 내가 바꾸려는 값
  })
);

export const initializeForm = createAction(
  INITIALIZE_FORM,
  (form) => form
); // register

export const register = createAction(
  REGISTER,
  ({ email, password }) => ({
    email,
    password,
  })
);

export const login = createAction(
  LOGIN,
  ({ email, password }) => ({ email, password })
);

// 사가 생성
const registerSaga = createRequestSaga(
  REGISTER,
  authAPI.register
);

const loginSaga = createRequestSaga(LOGIN, authAPI.login);

export function* authSaga() {
  yield takeLatest(REGISTER, registerSaga);
  yield takeLatest(LOGIN, loginSaga);
}

// 또한 나중에 register -> login || login -> register로 가면 둘중 하나는 초기화 해 주는 작업이 필요하다.
// 여기에다가 로그인 폼 데이터를 저장해야 한다.
const initialState = {
  register: {
    email: "",
    password: "",
    passwordConfirm: "",
  },
  login: {
    email: "",
    password: "",
  },
  // register, login saga의 response data
  auth: null,
  authError: null,
};

const auth = handleActions(
  {
    [CHANGE_FIELD]: (state, { payload: { form, key, value } }) =>
      // 리덕스는 불변성을 유지해 줘야 한다.
      produce(state, (draft) => {
        draft[form][key] = value;
      }),
    [INITIALIZE_FORM]: (state, { payload: form }) => ({
      ...state,
      [form]: initialState[form],
    }),
    // 회원가입 성공
    [REGISTER_SUCCESS]: (state, { payload: auth }) => ({
      ...state,
      auth,
      authError: null,
    }),
    // 회원가입 실패
    [REGISTER_FAILURE]: (state, { payload: error }) => ({
      ...state,
      authError: error,
    }),
    // 로그인 성공
    [LOGIN_SUCCESS]: (state, { payload: auth }) => ({
      ...state,
      auth,
      authError: null,
    }),
    // 로그인 실패
    [LOGIN_FAILURE]: (state, { payload: error }) => ({
      ...state,
      authError: error,
    }),
  },
  initialState
);

export default auth;
