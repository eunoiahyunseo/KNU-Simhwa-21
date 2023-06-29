// foo();
// foo2();

// // var 변수 선언과 함수 선언문에서만 호이스팅이 일어납니다.
// // let/const 변수 선언과 함수표현식에서는 호이스팅이 발생하지 않습니다.
// function foo() {
//   console.log("hello world!");
// }

// var foo2 = function () {
//   console.log("hello2 world!");
// };

// printName();

// function printName(firstName) {
//   var result = inner();
//   console.log(typeof inner);
//   console.log("name is " + result);

//   function inner() {
//     return "inner value";
//   }
// }

// function add() {
//   var i,
//     sum = 0;

//   for (i = 0; i < arguments.length; i++) {
//     sum += arguments[i];
//   }
//   document.write("수행 결과 : " + sum + "<p />");
//   console.log(arguments);
// }

// add(2, 3);
// add(2, 3, 4);
// add(2, 3, 4, 5);

// var arr = [1, 2, 3, 4, "5"];

// function printArr() {
//   var i,
//     sum = 0;

//   for (i = 0; i < arr.length; i++) {
//     sum += arr[i];
//   }
//   return sum;
// }

// var result = printArr();

// document.write("배열 원소 합 : " + result + "<br />");

// const array = [1, 2, 3];

// const array2 = array.concat(4);
// console.log(array);
// console.log(array2);

// const coke = {
//   name: "coca",
//   price: 2980,
// };

// var new_coke = { ...coke };
// coke.name = "pepsi";
// console.log(coke, new_coke);

// const ndata1 = [3, 5, 2, 1];
// document.write(
//   "수치정렬 : " +
//     ndata1.sort(function (a, b) {
//       return a - b;
//     })
// );

// const kdata = [1, 2, 3, 4, 5];

// const str1 = kdata.splice(1, 2, 6, 7, 8);
// console.log(kdata);
// console.log(str1);

// const data = [1, 2, 3, 4];

// // 조건에 맞는 것만 걸러내는 것이다. ㅈㄱ 이 예제에서는 2보다 큰 것만 빼내서 배열로 ㅁ나들어 냄
// const filteredData = data.filter((value) => value > 2);
// console.log(filteredData);
// console.log(data);

// const data = [10, 20, 30, 40, 40, 60, 70, 30, 90, 100];
// console.log(data.indexOf(30, 2));

// console.log(this === window);

// var a = 1;

// function outer() {
//   var a = 3;
//   {
//     var a = 4;
//     console.log(a);
//   }
//   console.log(a);
// }

// outer();
// console.log(a);

// const Array = new global.Array("1", "2", "3", "4");

// Array.map((value) => {
//   console.log(value);
// });

// age = 20;

// const cat = {
//   name: "neow",
//   age: 21,
//   foo: function () {
//     // 화살표 함수에는 this라는 변수 자체가 존재하지 않기 때문에
//     // 그 상위 환경에서의 this를 참조하게 됩니다.
//     const foo2 = () => {
//       console.log(this.age);
//     };
//     foo2();
//   },
// };

// cat.foo();

// age = 20;

// const cat = {
//   name: "neow",
//   callName: () => {
//     console.log(this);
//   },
// };

// cat.callName();

// const obj = {
//   name: "hyunseo",
//   a: function () {
//     console.log(this.name);
//   },
// };

// const obj2 = {
//   name: "hyunseo2",
// };

// // obj.a.bind(obj2).call();
// // obj.a.call(obj2);
// obj.a.apply(obj2);

// function Person(name, age) {
//   this.name = name;
//   this.age = age;
// }

// Person.prototype.sayHi = function () {
//   console.log(this.name, this.age);
// };

// const person1 = new Person("hyunseo", 21);
// console.log(person1.name, person1.age);

// const newScope = (function () {
//   var x = "local";
//   function y() {
//     alert(x);
//   }
//   return { y: y };
// })();

// console.log(newScope.y());

// function outerFn() {
//   let x = 10;

//   return function innerFn(y) {
//     return (x = x + y);
//   };
// }

// let a = outerFn();
// let b = outerFn();
// console.log(a(5));
// console.log(a(5));
// console.log(a(5));
// console.log(b(5));

// let globalFn;

// {
//   let x = 10;
//   globalFunc = function (y) {
//     return (x = x + y);
//   };
// }

// console.log(globalFunc(5));
// console.log(globalFunc(5));
// console.log(globalFunc(5));

// let outFn = function () {
//   let x = 10;
//   return function (y) {
//     return (x = x + y);
//   };
// };

// let b = outFn();
// console.log(b(5));
// console.log(b(5));

// var x = 1;

// function varTest() {
//   var x = 3;
// }

// varTest();

// console.log(x);

const newScope = (function () {
  var x = "local";
  const addElement = function () {
    const header = document.createElement("h3");
    const textNode =
      document.createTextNode("내 이름은 이현서 입니다.");

    header.appendChild(textNode);
    document.getElementById("Dominsert").appendChild(header);
  };
  return {
    add: function () {
      addElement();
    },
  };
})();

// jquery의 ready event는 DOM이 다 로드 된 다음에 실행된다.
// 왜냐하면 document가 준비되어야 event가 발생하기 때문이다.
var n = 0;

$(document).ready(function () {
  var myElement = $("div#Dominsert");
  myElement.text("Hello Hyunseo!");

  $("button.hide").click(function () {
    console.log(this);
    $("p").hide();
  });

  $("button.show").click(function () {
    $("p").show();
  });

  $("ans").hide();
  $("p.q1").click(function () {
    $("ans.q1").show();
  });

  $("ans.q1").click(function () {
    $(this).hide();
  });

  $("div.out").mouseover(function () {
    $("p:first", this).text("마우스 포인트 들어옴");
    $("p:last", this).text(++n);
  });

  $("div.out").mouseleave(function () {
    $("p:first").text("마우스 포인트 나감");
    $("p:last").text("최종 횟수 : " + n);
  });

  //   $("button").click(function () {
  //     $("h1, h2, p, div").toggleClass("red");
  //   });

  $("#out").click(function () {
    $("img").fadeOut("slow");
  });

  $("#in").click(function () {
    $("img").fadeIn("slow");
  });
});

function move(obj, time) {
  $(obj).stop().animate(
    {
      left: 350,
      top: 0,
    },
    time
  );
}

function back(Css) {
  $(css).stop().animate({
    left: 0,
    top: 0,
  });
}
