// 호이스팅이란 스코프가 전역이라면 해당 스크립트의 최상단으로 끌어올려지고 스코프가 함수 내부에 국한된다면 해당 함수의 최상단으로
// 끌어 올리는 것을 의미한다. 또한 선언부만 끌어올리는 것입니다. 할당은 이루어지지 않습니다.

printMsg("호출");

function printMsg(msg) {
  console.log("무명함수 >> ", msg);
}

// var printMsg = function (msg) {
//   console.log("기본함수 >> ", msg);
// };
