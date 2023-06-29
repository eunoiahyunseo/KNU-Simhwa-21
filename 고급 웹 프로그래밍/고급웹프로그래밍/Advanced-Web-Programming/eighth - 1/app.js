const http = require("http");

http
  .createServer((req, res) => {
    res.writeHead(200, { "Content-Type": "text/plain" });
    res.end("Hello\n");
  })
  .listen(7777, () => {
    console.log("listening at 7777");
  });

http
  .createServer((req, res) => {
    res.writeHead(200, { "Content-Type": "text/plain" });
    res.end("World\n");
  })
  .listen(8888, () => {
    console.log("listening at 8888");
  });
