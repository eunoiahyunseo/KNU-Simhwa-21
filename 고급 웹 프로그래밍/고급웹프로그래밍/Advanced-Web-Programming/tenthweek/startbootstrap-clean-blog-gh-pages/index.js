const express = require("express");
const mongoose = require("mongoose");
const fileUpload = require("express-fileupload");
const expressSession = require("express-session");
const fs = require("fs");
const ejs = require("ejs");

const { validateMiddleware } = require("./util/Form");

const newPostController = require("./controllers/newPost");
const homeController = require("./controllers/home");
const storePostController = require("./controllers/storePost");
const getPostController = require("./controllers/getPost");
const newUserController = require("./controllers/newUser");
const storeUserController = require("./controllers/storeUser");
const loginController = require("./controllers/login");
const loginUserController = require("./controllers/loginUser");
const logoutController = require("./controllers/logout");

const authMiddleware = require("./middleware/authMiddleware");
const redirectIfAuthenticatedMiddleware = require("./middleware/redirectIfAuthenticatedMiddleware");
const app = express();

// set template engine
app.set("view engine", "ejs");
app.set("PORT", process.env.PORT || 4000);

(async () => {
  await mongoose
    .connect(
      "mongodb+srv://hyunseo4:1234@cluster0.zpso2td.mongodb.net/?retryWrites=true&w=majority",
      {
        dbName: "awp",
      }
    )
    .then(() =>
      console.log("mongodb에 성공적으로 연결되었습니다.")
    );
})();

global.loggedIn = null;

app.use(
  expressSession({
    secret: "keyboard cat",
  })
);
app.use("/", express.static("public"));
app.use(express.urlencoded({ extended: true }));
app.use(express.json());
app.use(
  fileUpload({
    limits: { fileSize: 50 * 1024 * 1024 },
  })
);

app.use(async (req, res, next) => {
  if (!fs.existsSync("./public/img")) {
    fs.mkdirSync("./public/img");
    console.log("성공적으로 img폴더를 생성하였습니다.");
  }
  next();
});

app.use("*", (req, res, next) => {
  loggedIn = req.session.userId;
  next();
});

app.get("/", homeController);
app.get("/post/:id", getPostController);
app.post(
  "/posts/store",
  authMiddleware,
  validateMiddleware,
  storePostController
);

app.get("/posts/new", authMiddleware, newPostController);

app.get(
  "/auth/register",
  redirectIfAuthenticatedMiddleware,
  newUserController
);
app.post(
  "/users/register",
  redirectIfAuthenticatedMiddleware,
  storeUserController
);

app.get(
  "/auth/login",
  redirectIfAuthenticatedMiddleware,
  loginController
);
app.post(
  "/users/login",
  redirectIfAuthenticatedMiddleware,
  loginUserController
);

app.get("/auth/logout", logoutController);

app.listen(app.get("PORT"), () => {
  console.log(`*:listening on port ${app.get("PORT")}`);
});
