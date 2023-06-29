const express = require("express");
const cors = require("cors");
const multer = require("multer");
const path = require("path");
const bodyParser = require("body-parser");

const app = express();

app.set("port", process.env.PORT || 8001);

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());
app.use(express.json());
app.use(cors());

const upload = multer({
  storage: multer.diskStorage({
    destination: function (req, file, cb) {
      cb(null, "uploads/");
    },
    filename: function (req, file, cb) {
      cb(
        null,
        new Date().valueOf() +
          path.extname(file.originalname)
      );
    },
  }),
  limits: { fileSize: 100 * 1024 * 1024 },
});

app.get("/", (req, res) => {
  res.status(200).json({ api: "ok", status: 200 });
});

app.post(
  "/test",
  upload.single("image"),
  (req, res) => {
    console.log("file ceck >> ", req.file);
    console.log(req.body);
    res.status(201).json({
      data: {
        file: req.file.originalname,
        age: req.body.age,
      },
      status: 201,
    });
  }
);

app.listen(app.get("port"), function () {
  console.log(
    `App listening on port ${app.get("port")}.`
  );
});
