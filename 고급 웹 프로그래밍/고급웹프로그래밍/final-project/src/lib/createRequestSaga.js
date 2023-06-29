import { call, put } from "redux-saga/effects";
import { startLoading, finishLoading } from "../modules/loading";

export const createRequestActionTypes = (type) => {
  const SUCCESS = `${type}_SUCCESS`;
  const FAILURE = `${type}_FAILURE`;
  return [type, SUCCESS, FAILURE];
};

// saga function을 return하는 HOC를 작성해 줘야 한다.
// 이를 하기 위해서는 일단 type과 request인자를 받아야 한다.
export default function createRequestSaga(type, request) {
  /* eslint-disable-next-line */
  const [_, SUCCESS, FAILURE] = createRequestActionTypes(type);
  return function* (action) {
    // 요청 시작
    yield put(startLoading(type));

    // 요청 본문 시작
    try {
      const response = yield call(request, action.payload);
      yield put({
        type: SUCCESS,
        payload: response.data,
        meta: response,
      });
    } catch (e) {
      yield put({
        type: FAILURE,
        payload: e,
        error: true,
      });
    }
    // 요청의 끝
    yield put(finishLoading(type));
  };
}
