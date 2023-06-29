"use strict";
// const obj = [
//   {
//     name: "hyunseo1",
//     age: 21,
//   },
//   {
//     name: "hyunseo2",
//     age: 22,
//   },
//   {
//     name: "hyunseo3",
//     age: 23,
//   },
// ];

// const cpyObj = [...obj, { name: "hyunseo4", age: 24 }];

// const preTag = document.createElement("PRE");
// preTag.innerHTML = JSON.stringify(cpyObj, null, 2);
// preTag.style.fontSize = "2rem";

// document.querySelector("body").appendChild(preTag);

const obj = {
  name: "hyunseo",
  age: 21,
  printInfo() {
    // const printInfo_ = function () {
    //   console.log(this);
    // };

    const printInfo_ = () => {
      console.log(this);
    };
    printInfo_();
  },
  printInfo2: function () {
    console.log(this);
  },
};

// const printInfoTemp = obj.printInfo.bind(obj);

// printInfoTemp();

obj.printInfo2();
