// HW01

/**
 * ES6의 문법으로 서 forEach, for ...in, for ...of가 있고, 실무에서도 몇번 사용해 보았습니다.
 */

/**
 * forEach는 그냥 말로 넘어가면 Array, Map, Set객체에서 지원하며 forEach의 callback함수로 등록된
 * 함수가 반복 될 때마다 실행되는 방식입니다. callback에서는 인덱스와 값에 접근할 수 있다는 것이 특징입니다.
 */

/**
 * for ..in은 객체의 속성들을 반복하여 작업을 수행할 수 있습니다. 이의 for ..of와 큰 특징은 객체의 key값에 접근할 수 있지만
 * value값에 접근하는 방법은 제공하지 않는다는 것입니다. 또한 [[Enumerable]]의 속성을 가진 열거형 자바스크립트 객체만이 사용 대상이 됩니다.
 */

const obj = [
  {
    name: "hyunseo",
    age: 21,
  },
  {
    name: "hyunseo2",
    age: 22,
  },
  {
    name: "hyunse3",
    age: 24,
  },
];

for (let prop in obj) console.log(prop, obj[prop]);

/**
 * for ..of는 ES6에 추가된 새로운 컬렉션 전용 반복 구문으로서, [Symbol.iterator]속성을 명새해 주어야 사용 가능합니다.
 */

for (let prop of obj) console.log(prop);

/**
 * 간단하게 객체에서는 for ..in을 사용하면 좋고 배열에서는 for ..of를 사용하면 좋습니다.
 */


