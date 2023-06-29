const http = require("http");
const fs = require("fs");
const path = require("path");
const url = require("url");

http
  .createServer((req, res) => {
    const q = url.parse(req.url, true);
    const filename = "." + q.pathname;

    fs.readFile(path.resolve(__dirname, filename), (err, data) => {
      if (err) {
        res.writeHead(404, { "Content-Type": "text/html" });
        return res.end("404 Not Found");
      }
      res.writeHead(200, { "Content-Type": "text/html" });
      res.write(data);
      return res.end();
    });
  })
  .listen(8001, () => {
    console.log("server is listening in port 8001");
  });
