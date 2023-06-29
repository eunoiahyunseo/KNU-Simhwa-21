import React from "react";
import ReactDOM from "react-dom/client";
import App from "./App";
import { BrowserRouter } from "react-router-dom";
import { HelmetProvider } from "react-helmet-async";

import { Provider } from "react-redux";
import { createStore, applyMiddleware } from "redux";
import { composeWithDevTools } from "redux-devtools-extension";
import rootReducer, { rootSaga } from "./modules";
import createSagaMiddleware from "redux-saga";
import logger from "redux-logger";
import { tempSetUser, check } from "./modules/user";

const sagaMiddleware = createSagaMiddleware();

const store = createStore(
  rootReducer,
  composeWithDevTools(
    // logger는 development환경에서만 실행되게 해야 한다.
    process.env.NODE_ENV === "development"
      ? applyMiddleware(logger, sagaMiddleware)
      : applyMiddleware(sagaMiddleware)
    // applyMiddleware(logger, sagaMiddleware)
  )
);

function loadUser() {
  try {
    const user = localStorage.getItem("user");
    if (!user) return;
    store.dispatch(tempSetUser(JSON.parse(user)));
    store.dispatch(check());
  } catch (e) {
    console.log("error occured in localStorage", e);
  }
}

const root = ReactDOM.createRoot(
  document.getElementById("root")
);

sagaMiddleware.run(rootSaga);
loadUser();

root.render(
  <Provider store={store}>
    <BrowserRouter>
      <HelmetProvider>
        <App />
      </HelmetProvider>
    </BrowserRouter>
  </Provider>
);
