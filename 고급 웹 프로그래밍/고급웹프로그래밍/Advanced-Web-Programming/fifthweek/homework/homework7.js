const func1 = function (a, b) {
  const c = a + 5 + 100;
  return c;
};

console.log(func1(1, 2));

const func2 = (a, b) => {
  const c = a + 5 + 100;
  return c;
};

console.log(func2(1, 2));

/**
 * 참고로 화살표 함수 안에서의 this와 함수 표현식 안에서의 this는 다른데
 * 막 React에서 사용할 때 중요하게 배울 개념입니다.
 */
