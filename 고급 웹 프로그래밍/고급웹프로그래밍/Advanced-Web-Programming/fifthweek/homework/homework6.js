/**
 * W3 School의 말을 빌리면
 * const는 ES6에 도입된 키워드 입니다.
 * 1. const로 선언된 변수는 재선언이 불가능합니다.
 * 2. const로 선언된 변수는 재할당이 불가능합니다.
 * 3. const로 선언된 변수는 Block Scop를 가집니다.
 */

// const PI = 3.14;
// PI = 3.14;
// PI = PI + 10;
//TypeError: Assignment to constant variable.
/**
 * 와 같은 에러를 컴파일러가 띄우게 됩니다.
 */

/**
 * 또한 선언될 떄 초기화가 되어야 합니다. 다음과 같은 구문은 오류를 띄웁니다.
 */

// const PI;
// PI = 3.14;
//SyntaxError: Missing initializer in const declaration

/**
 * 또한 일반적인 규칙인데 우리가 변수의 값이 바뀔 지 모르면 헝성 const로 선언하는 것이좋습니다.
 * 1. A new Array
 * 2. A new Object
 * 3. A new function
 * 4. A new RegExp
 * 위 4가지의 선언에서 const를 자주 사용하게 됩니다.
 */

// 이는 배열에서의 기본 사용 예시입니다.
// const cars = ["a", "b", "c"];
// cars[0] = "d";
// cars.push("e");

// 하지만 다음과 같이 재할당은 불가능합니다.
// const cars = ["a", "b", "c"];
// cars = ["d", "e", "f"];

// 이는 객체에서의 기본 사용 예시입니다.
// const car = {
//   type: "Fiat",
//   model: "500",
//   color: "white",
// };

// car.color = "red";
// car.owner = "Johnson";

// 하지만 다음과 같이 배열에서처럼 재할당은 불가능합니다.
// const car = {type:"Fiat", model:"500", color:"white"};
// car = {type:"Volvo", model:"EX60", color:"red"};

/**
 * 또한 Block scope을 지원한다고 했었는데 간단한 예시는 아래와 같습니다.
 */

// const x = 10;
// console.log(x); // 10

// {
//   const x = 2;
//   console.log(x); // 2
// }

// 다음과 블럭 안에서 다른 값을 가질 수 있습니다.

/**
 * 또한 한 Block scope안에서 같은 이름으로 선언된 변수를 즉 let이나 var로 선언된 변수를
 * 같은 scope안에서 아래와 같이 재 할당 하는 것은 허용되지 않습니다.
 */

// var x = 2; // Allowed
// const x = 2; // Not allowed

// {
//   let x = 2; // Allowed
//   const x = 2; // Not allowed
// }

// {
//   const x = 2; // Allowed
//   const x = 2; // Not allowed
// }

/**
 * 또한 아까 수업 시간에도 보았지만 자바스크립트는 기본적으로 맨 위로 선언문을 올리는 hoisting을 컴파일 하기 전에 진행합니다.
 * 실제로 하는 것은 아니고 그렇게 보이도록 하는 것인데, const는 선언과 동시에 초기화되기 때문에 위로 올려도 초기화가 되지 않아
 * ReferenceError를 띄우고 변수를 사용하지 못합니다.
 */

// console.log(carName);
// const carName = "Volvo";
//ReferenceError: Cannot access 'carName' before initialization
