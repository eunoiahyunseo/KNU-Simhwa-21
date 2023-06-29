/**
 * Map객체는 key-value쌍으로 이루어진 자료구조입니다. 이는 대개 해시 함수를 이용해서
 * 검색 최적화를 할 때 주로 사용됩니다.
 */

const fruits = new Map();

fruits.set("apples", 500);
fruits.set("bananas", 300);
fruits.set("orangesa", 200);
fruits.set("apples", 300);

console.log(fruits.get("apples"));

// map의 사이즈
console.log(fruits.size);

// map 초기화
fruits.clear();

console.log(fruits.size);

fruits.set("apples", 500);
fruits.set("bananas", 300);
fruits.set("orangesa", 200);

// 키가 apple인 것 삭제
fruits.delete("apples");

// map객체에 key가 apples인것이 있을 때
if (fruits.has("apples")) {
  console.log("map has apples");
} else {
  console.log("map has no apples");
}

// 모든 키 - 값 쌍 출력
let text = "";
if (fruits instanceof Map) {
  fruits.forEach((value, key) => {
    text += "\n" + key + ` = ` + value;
  });
}
console.log(text);

// 모든 키 출력
for (const x of fruits.keys()) {
  console.log(x);
}

// 모든 값 출력
for (const x of fruits.values()) {
  console.log(x);
}

// 또한 entries()메소드는 iterator객체를 리턴합니다.
// [key, value]으로 이루어진 객체 입니다.
for (const x of fruits.entries()) {
  console.log(x);
}
