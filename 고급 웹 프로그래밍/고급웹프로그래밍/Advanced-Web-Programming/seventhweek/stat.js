const fs = require("fs");

console.log("Going to get file info!");
fs.stat("input.txt", (err, stats) => {
  if (err) return console.error(err);
  console.log(stats);
  console.log("Got file info successfully!");

  console.log("isFile ? " + stats.isFile());
  console.log("isDirectory ? " + stats.isDirectory());
});
