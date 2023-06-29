const http = require("http");
const fs = require("fs");
const path = require("path");
const dt = require("./myfirstmodule");

http
  .createServer((req, res) => {
    fs.readFile(path.resolve(__dirname, "./demofile1.html"), (err, data) => {
      if (err) {
        throw err;
      }
      res.write(data);
      return res.end();
    });
  })
  .listen(8001, () => {
    console.log("server is listening in port 8001");
  });
