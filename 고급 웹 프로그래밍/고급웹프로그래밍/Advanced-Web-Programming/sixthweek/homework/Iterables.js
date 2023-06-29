// 우리는 for..of를 string에서 사용할 수 있습니다.
for (const x of "W3Schools") {
  console.log(x);
}

// 또한 배열을 for..of loop로 반복시킬 수 있습니다.
for (const x of [1, 2, 3, 4, 5]) {
  console.log(x);
}

/**
 * JS의 객체 중 next()메소드를 구현한 객체는 iterator가 됩니다.
 * next()메소드는 반드시 두가지 속성을 반환해야 합니다. value와 done입니다.
 */

function myNumbers() {
  let n = 0;
  return {
    next: function () {
      n += 10;
      return {
        value: n,
        done: false,
      };
    },
  };
}

const n = myNumbers();
console.log(n.next());
console.log(n.next());
console.log(n.next());

// { value: 10, done: false }
// { value: 20, done: false }
// { value: 30, done: false }

myNumbers = {};

myNumbers[Symbol.iterator] = function () {
  let n = 0;
  done = false;
  return {
    next() {
      n += 10;
      if (n == 100) done = true;
      return { value: n, done: done };
    },
  };
};

for (const num of myNumbers) {
  console.log(num);
}

// 이처럼 또한 Symbol.iterator메소드를 구현한 객체는 자동적으로 for..of가 호출될 때 실행됩니다.

// 또한 우리는 아래와 같이 수동적으로 iterator를 호출해 줄 수 있습니다.
let iterator = myNumbers[Symbol.iterator](),
  result;
while (!(result = iterator.next()).done) {
  console.log(result);
}
