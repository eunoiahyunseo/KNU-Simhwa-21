/**
 * JavaScript의 변수는 local과 global scope에 속해질 수 있습니다.
 */

/**
 * function안에서는 안에서 선언된 변수를 참조 가능하다.
 */
// function myFunction() {
//   let a = 4;
//   return a * a;
// }

/**
 * function은 또한 함수 밖에서 선언된 변수도 참조 가능하다.
 */
// let a = 4;
// function myFunction2() {
//   return a * a;
// }

/**
 * 또한 함수 안에서 선언된 지역변수는 박에서 사용 불가능하다는 특징이 있다.
 */

/**
 * 또한 만약 우리가 어떤것을 counting할 때 counter가 함수실행이 끝나도 유지되었으면 좋겠을 때가 있을 수 있다.
 * 아래와 같은 예시같이 우리는 전역변수로 counter를 선언해서 하나씩 늘려나갈 수 있다.
 */

// let counter = 0;

// function add() {
//   counter += 1;
// }

// add();
// add();
// add();

// console.log(counter); // 3

/**
 * 또한 아래와 같은 예시는 당연히 counter값이 0이 나온다. 그 이유는 add함수 안에서
 * counter += 1; 을 하는 행위는 지역변수를 늘리는 것이 아니라 전역 변수를 늘리는 행위이기 때문이다.
 */

// let counter = 0;

// function add() {
//   let counter = 0;
//   counter += 1;
// }

// add();
// add();
// add();

// console.log(counter); // 0

/**
 * 하지만 아래 예시와 같이 전역변수에 선언을 지우고 지역변수만 선언해 주면 정상작동한다.
 * 하지만 결괏값은 아직 1로 이상하게 작동한다.
 */

// function add() {
//   let counter = 0;
//   counter += 1;
//   return counter;
// }

// add(); // 1
// add(); // 1
// console.log(add()); // 1

/**
 * 위와 같은 문제를 해결하기 위해서 JavaScript는 Nested Function을 지원하게 됩니다.
 * Javascript의 모든 함수는 한단계 위의 스코프에 접근 가능한 속성을 이용한 것입니다.
 */

// function add() {
//   let counter = 0;
//   function plus() {
//     counter += 1;
//   }
//   plus();
//   return counter;
// }

// console.log(add()); // 1

/**
 * 하지만 아직도 해결되지 않은 문제가 있는데 counter = 0을 한번만 실행시켜 주고 싶다
 * 여기서 우리는 clouser를 사용하게 되는 것이다.
 */

// const add = (() => {
//   let counter = 0;
//   return function () {
//     counter += 1;
//     return counter;
//   };
// })();

// add();
// add();
// console.log(add()); // 3

/**
 * 이 경우에는 clouser를 사용해서 add함수를 중첩함수로 만든 것입니다.
 * add()를 호출 하는것은 add함수가 반환하는 함수를 호출하는 것과 같습니다.
 * 즉 외부 호출을 한번만 해서 변수를 참조할 수 있게 된 것입니다.
 */

/**
 * 즉 우리는 클로저를 함수를 리턴하는 함수라고 오해할 수 있는데, 정확한 정의는 내부함수가 상위 스코퍼의 식별자를 참조하고 있고
 * 그 상위 스코프 밖에서 사용했을 때 그 상위 스코프의 식별자를 수정할 수 없는 형태라고 말하는 것이 옳습니다.
 */

/**
 * 이를 토대로 간단한 예시를 만들어 보았습니다.
 */

// let globalFunc;

// {
//   let x = 10;
//   globalFunc = function (y) {
//     return (x = x + y);
//   };
// }

// console.log(globalFunc(5)); // 15
// console.log(globalFunc(5)); // 20
// console.log(globalFunc(5)); // 25

/**
 * callback함수란 간단히 어떠한 함수의 인자로서 넘겨지는 것으로, 외부 함수의 안에서 어떠한 행동이 끝나고
 * 어떠한 routine이나 action을 실행시키게 할 때 사용됩니다.
 *
 * 또한 원래 callback함수는 비동기 함수가 완료되고 나서 무엇을 할지 지정해 주는데 사용되곤 합니다 .then()블럭 안에서 말이죠
 * 간단한 예시를 아래와 같이 만들어보았습니다. (비동기 안에서의 callback을 이해하기 위해)
 */

// function greeting(name) {
//   console.log(name);
// }

// (function CallbackExample(callback) {
//   return new Promise((resolve) => {
//     setTimeout(() => {
//       resolve(callback);
//     }, 3000);
//   });
// })(greeting).then((callback) => callback("hyunseo"));

// 3초후에 hyunseo가 출력된다.
