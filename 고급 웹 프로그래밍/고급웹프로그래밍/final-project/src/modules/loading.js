import { createAction, handleActions } from "redux-actions";

const START_LOADING = "loading/START_LOADING";
const FINISH_LOADING = "loading/FINISH_LOADING";
/**
 * 요청을 위한 타입을 payload로 설정해 줘야 한다. 예를 들어 "sample/GET_POST"와 같이
 */

export const startLoading = createAction(
  START_LOADING,
  (requestType) => requestType
);

export const finishLoading = createAction(
  FINISH_LOADING,
  (requestType) => requestType
);

const initialState = {};

const loading = handleActions(
  {
    [START_LOADING]: (state, { payload }) => ({
      ...state,
      [payload]: true,
    }),
    [FINISH_LOADING]: (state, { payload }) => ({
      ...state,
      [payload]: false,
    }),
  },
  initialState
);

export default loading;
