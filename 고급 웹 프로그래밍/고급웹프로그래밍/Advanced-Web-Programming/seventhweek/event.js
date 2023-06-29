const fs = require("fs");
const path = require("path");
const { EventEmitter } = require("events");

const eventEmitter = new EventEmitter();

// eventEmitter.on("test", () => {
//   console.log("test is working!");
// });

// eventEmitter.emit("test");

const rs = fs.createReadStream("input.txt");
const ws = fs.createWriteStream("input2.txt");

rs.on("close", () => {
  console.log("rs closed!");
});

ws.on("close", () => {
  console.log("ws closed!");
});

rs.on("open", () => {
  console.log("The file is open");
});

rs.on("data", (chunk) => {
  console.log("data is writing");
  ws.write(chunk);
});
