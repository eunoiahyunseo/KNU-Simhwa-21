import { createAction, handleActions } from "redux-actions";
import createRequestSaga, {
  createRequestActionTypes,
} from "../lib/createRequestSaga";
import * as authAPI from "../lib/api/auth";
import { takeLatest } from "redux-saga/effects";

const CHANGE_FIELD = "profile/CHANGE_FIELD";
const [
  UPDATE_PROFILE,
  UPDATE_PROFILE_SUCCESS,
  UPDATE_PROFILE_FAILURE,
] = createRequestActionTypes("profile/UPDATE_PROFILE");

export const changeField = createAction(
  CHANGE_FIELD,
  ({ key, value }) => ({
    key,
    value,
  })
);

/**
 * payload에는
 * {
 *  id: string,
 *  email: string,
 *  username: string
 * }
 * 와 같은 형식의 data가 들어와야 한다.
 */
export const updateProfile = createAction(
  UPDATE_PROFILE,
  (profile) => profile
);

// 프로필을 업데이트하는 사가 만들기
const updateProfileSaga = createRequestSaga(
  UPDATE_PROFILE,
  authAPI.editProfile
);

export function* profileSaga() {
  yield takeLatest(UPDATE_PROFILE, updateProfileSaga);
}

const initialState = {
  username: "",
  email: "",
  profileError: null,
};

const profile = handleActions(
  {
    [CHANGE_FIELD]: (state, { payload: { key, value } }) => ({
      ...state,
      [key]: value,
    }),
    [UPDATE_PROFILE_SUCCESS]: (
      state,
      { payload: { email, username } }
    ) => ({
      ...state,
      email,
      username,
    }),
    [UPDATE_PROFILE_FAILURE]: (
      state,
      { payload: profileError }
    ) => ({
      ...state,
      profileError,
    }),
  },
  initialState
);

export default profile;
