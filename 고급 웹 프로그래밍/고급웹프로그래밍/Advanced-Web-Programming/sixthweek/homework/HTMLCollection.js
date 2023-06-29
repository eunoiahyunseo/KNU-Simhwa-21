/**
 * getElementsByTagName()메소드는 HTMLCollection객체를 리턴하게 됩니다. 이는 HTML element의
 * 배열과 같은 것입니다.
 */

const myCollection = document.getElementsByTagName("form");
// 이는 인덱스로 접근 가능합니다. -> 결과 dom element
console.log(myCollection[0]);

// 이는 length getter를 제공합니다.
for (let i = 0; i < myCollection.length; i++) {
  myCollection[i].style.color = "red";
}
// 이렇게 하게되면 form객체의 color가 빨간색이 됩니다.
