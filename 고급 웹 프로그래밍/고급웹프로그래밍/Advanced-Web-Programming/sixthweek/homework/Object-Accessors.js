/**
 * ECMAScript 5부터 Getter와 Setter가 도입되었습니다.
 */

const person = {
  firstName: "John",
  lastName: "Doe",
  language: "",
  get lang() {
    return this.language;
  },
  set lang(lang) {
    this.language = lang;
  },
  get fullName() {
    return this.firstName + " " + this.lastName;
  },
  fullName_: function () {
    return this.firstName + " " + this.lastName;
  },
};

person.lang = "en"; // setter
console.log(person.lang); // getter // en

/**
 * 이와 같이 fullName을 함수로 불러올 수도 있고 getter를 통해서 불러올 수도 있습니다.
 * 하지만 이 둘의 차이는 함수는 function으로 불러온 다는 것이고 getter는 속성으로써 불러온 다는 것입니다.
 * 즉 getter가 더 간단한 문법을 제공한다는 장점이 있습니다.
 */

console.log(`by function >> ${person.fullName_()}`); // by function >> John Doe
console.log(`by getter >> ${person.fullName}`); // by function >> John Doe

console.log("\n");

const person2 = {
  firstName: "John",
  lastName: "Doe",
  language: "",
  get lang() {
    return this.language.toUpperCase();
  },
  set lang(lang) {
    this.language = lang.toUpperCase();
  },
};

// 이와 같이 getter안에 계산된 값을 넣을 수도 있습니다.
person2.lang = "en";
console.log(person2.lang); // EN

console.log("\n");

const obj = { counter: 0 };

Object.defineProperty(obj, "reset", {
  get: function () {
    this.counter = 0;
  },
});

Object.defineProperty(obj, "increment", {
  get: function () {
    this.counter++;
  },
});

Object.defineProperty(obj, "decrement", {
  get: function () {
    this.counter--;
  },
});

Object.defineProperty(obj, "add", {
  set: function (value) {
    this.counter += value;
  },
});

Object.defineProperty(obj, "subtract", {
  set: function (value) {
    this.counter -= value;
  },
});

obj.reset;
obj.add = 5;
obj.subtract = 1;
obj.increment;
obj.decrement;

console.log(`obj counter >> ${obj.counter}`);

// 여기서 Object.defineProperty가 궁금해서 조금 더 조사해 보았습니다.

const dessert = {
  dessertName: "chocolate cake",
  sweetness: 6,
  ingredient: ["flour", "eggs", "chocolate", "sugar", "butter"],
};

// 기본적으로 configureable, enuerable키가 기본값인 false로 되어 있으므로 값을 삭제할 수 없고 for...in문에나 Object.keys()등으로 접근하여
// 순회할 수 없습니다. 또한 writeable키도 기본값 false로 되어 있어서 할당 연산자로 값을 수정할 수 없습니다.
/*
Object.defineProperty(dessert, "price", {
  value: "20$",
  //   enumerable: true,
});
*/

let cakePrice = "20$";

Object.defineProperty(dessert, "price", {
  enumerable: true,
  configureable: true,
  get: function () {
    return `${this.dessertName}-${cakePrice}`;
  },
  set: function (newValue) {
    this.dessertName = newValue;
  },
});

console.log(dessert.price);

for (key in dessert) {
  console.log(key);
}

dessert.price = "strawberry cake";
console.log(dessert.price);

/**
 * 만약에 dessert객체에 새로운 프로펴티를 추가하고 싶으면 위와같이 할당 연산자를 사용해서 간단하게 추가할 수 있습니다.
 * 만약에 위 코드처럼 값을 할당하여 속성을 추가하는 일반적인 방법을 사용하면 자동으로 enumerable과 configureable, writeable속성이 true가 됩니다.
 * enumerable : true이기 때문에 값을 for...in문 등의 방법으로 열거할 수 있고,
 * configureable: true이기 때문에 delete등을 사용하여 속성을 삭제할 수 있고,
 * writeable : true이기 때문에 추후에 할당 연산자로 값을 변경할 수 있습니다.
 */

/**
 * 여기서 defineProperty를 사용할 수 있는데, 이는 매개변수로 순서대로 obj, prop, descriptor를 받습니다.
 * 여기서 속성 서술자((descriptor)는 데이터 서술자와 접근자 서술자로 나뉩니다.
 * 데이터 서술자는 값을 가지는 속성이고, 접근자 서술자는 접근자(getter), 서술자(setter)한 쌍을 가지는 속성입니다.
 */

var o = {};

Object.defineProperty(o, "a", {
  value: 37,
  writable: false,
});

console.log(o.a);
o.a = 25;

console.log(o.a);

// (() => {
//   "use strict";
//   var o = {};
//   Object.defineProperty(o, "b", {
//     value: 2,
//     writable: false,
//   });
//   o.b = 3;
//   return o.b;
// })();

var o = {};

// Object.defineProperty(o, "a", {
//   value: 1,
//   enumerable: true,
// });

// Object.defineProperty(o, "b", {
//   value: 2,
//   enumerable: false,
// });

// Object.defineProperty(o, "c", {
//   value: 3,
// });

// o.d = 4;

// for (var i in o) {
//   console.log(i);
// }

// Object.defineProperty(o, "a", {
//   get() {
//     return 1;
//   },
//   configurable: false,
// });

// Object.defineProperty(o, "a", {
//   configurable: true,
// });

// console.log(o.a);

function Archiver() {
  var temperature = null;
  var archive = [];

  Object.defineProperty(this, "temperature", {
    get: function () {
      console.log("get!");
      return temperature;
    },
    set: function (value) {
      temperature = value;
      archive.push({ val: temperature });
    },
  });

  this.getArchive = () => {
    return archive;
  };
}

var arc = new Archiver();
arc.temperature;
arc.temperature = 11;
arc.temperature = 13;
console.log(arc.getArchive());

const object = {
  age: 1,
  print() {
    console.log(this);
  },
  print2: function () {
    console.log(this);
  },
  print3: () => {
    console.log(this);
  },
  print4: function () {
    const test = function () {
      console.log(this);
    };
    test();
  },
};

function foo() {
  console.log("invoked");
}

// global.setInterval(() => {
//   console.log("asdf");
// }, 1000);

const cat = {
  name: "meow",
  callName: () => console.log(this.name),
};

cat.callName();

// const Foo = () => {};
// const foo_ = new Foo();

// const button = document.getElementById("myButton");

// button.addEventListener("click", () => {
//   console.log(this); // Window
//   this.innerHTML = "clicked";
// });

// button.addEventListener("click", function () {
//   console.log(this);
//   this.innerHTML = "clicked";
// });

// function foo() {
//   return (a) => {
//     console.log(this.a);
//   };
// }

// let obj = {
//   a: 2,
// };

// let obj2 = {
//   a: 3,
// };

// let bar = foo.call(obj1);
// bar.call(obj2);

// function foobaz() {
//   return {
//     first: "hyunseo",
//     last: "lee",
//     asyncFn: function () {
//       console.log(this);
//       setTimeout(() => {
//         console.log(this.first);
//       }, 1000);
//     },
//   };
// }

// let foobaz_ = foobaz();
// foobaz_.asyncFn();

// { first: 'hyunseo', last: 'lee', asyncFn: [Function: asyncFn] }
// hyunseo

function Prefixer(prefix) {
  this.prefix = prefix;
}

Prefixer.prototype.prefixArray = function (arr) {
  console.log(this);
  return arr.map(
    function (x) {
      return this.prefix + " " + x;
    }.bind(this)
  );
};

const pre = new Prefixer("Hi");
console.log(pre.prefixArray(["Lee", "Kim"]));

const person_ = {
  name: "Lee",
  sayHi: function () {
    console.log(`Hi ${this.name}`);
  },
};

console.log(person_.this);
person_.sayHi.bind(person_)();

let sese = {
  age: 20,
  say() {
    console.log(this.age);
  },
};

let sese2 = {
  age: 21,
};

sese.say.bind(sese2)();
