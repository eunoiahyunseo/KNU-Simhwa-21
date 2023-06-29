const fs = require("fs");
const path = require("path");

fs.writeFile("mynewfile3.txt", "hello content!", function (err) {
  if (err) throw err;
  console.log("Saved3");
});

fs.open("mynewfile2.txt", "w", function (err, file) {
  if (err) throw err;
  console.log("Saved1");

  fs.appendFile(
    path.resolve(__dirname, "./mynewfile2.txt"),
    "Hello Content!",
    function (err) {
      if (err) throw err;
      console.log("Saved2");

      fs.unlink("mynewfile2.txt", function (err) {
        if (err) throw err;
        console.log("File deleted!");
      });
    }
  );
});

// const url = require("url");
// const adr = "http://localhost:8080/default.html?year=2017&month=february";
// const q = url.parse(adr, true);

// console.log(q.host);
// console.log(q.pathname);
// console.log(q.search);

// const qdata = q.query;
// console.log(JSON.stringify(qdata, null, 2));
