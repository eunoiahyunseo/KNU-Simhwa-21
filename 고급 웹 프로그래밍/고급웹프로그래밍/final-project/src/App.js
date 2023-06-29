import { Route, Routes } from "react-router-dom";
import loadable from "@loadable/component";
import GlobalStyle from "./lib/styles/globalStyles";
import { ThemeProvider } from "styled-components";
import { Helmet } from "react-helmet-async";

import { theme } from "./lib/styles/theme";

const LoginPage = loadable(() => import("./pages/LoginPage"));
const RegisterPage = loadable(() =>
  import("./pages/RegisterPage")
);
const WritePage = loadable(() => import("./pages/WritePage"));
const PostListPage = loadable(() =>
  import("./pages/PostListPage")
);
const PostPage = loadable(() => import("./pages/PostPage"));

const ProfilePage = loadable(() =>
  import("./pages/ProfilePage")
);

function App() {
  return (
    <>
      <Helmet>
        <title>STUIK</title>
      </Helmet>
      <ThemeProvider theme={theme}>
        <GlobalStyle />
        <Routes>
          <Route path={"/"} element={<PostListPage />} />
          <Route path={"/login"} element={<LoginPage />} />
          <Route path={"/register"} element={<RegisterPage />} />
          <Route path="/write" element={<WritePage />} />
          <Route path={"/profile"} element={<ProfilePage />} />
          <Route
            path="/@:username/:postId"
            element={<PostPage />}
          />
        </Routes>
      </ThemeProvider>
    </>
  );
}

export default App;
