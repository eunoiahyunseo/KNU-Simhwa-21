const express = require("express");
const cookieParser = require("cookie-parser");
const bodyParser = require("body-parser");
const apiRouter = require("./routes/api");
const { createClient } = require("redis");
const dotenv = require("dotenv");
const path = require("path");
const app = express();

app.set("port", process.env.PORT || 8001);

const client = createClient();
dotenv.config();

client.connect().then(() => {
  console.log("server is connected");
});
// Static File Serving
app.use("/static", express.static(path.resolve(__dirname, "./public")));

client.on("error", (err) => console.log("Redis Client Error", err));

// Body Parser
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

// Cookie
app.use(cookieParser("secrey_key"));

let value;

app.use(async (req, res, next) => {
  console.log("req.url >> ", req.url);
  value = await client.get(req.url);
  if (value) {
    return res.send(value);
  } else {
    req.redisURL = req.url;
    req.redisClient = client;
    next();
  }
});

app.use("/api", apiRouter);

app.get("/", (req, res) => {
  res.status(200).send("Good");
});

app.get("/about", (req, res) => {
  res.cookie("name", "hyunseo");
  res.status(201).json({ name: "hyunseo" });
});
app.listen(app.get("port"), function () {
  console.log(`App listening on port ${app.get("port")}.`);
});
