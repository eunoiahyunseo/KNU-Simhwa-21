/**
 * nodelist 객체는 document로부터 추출된 일종의 node리스트입니다.
 * 이는 HTMLCollection객체와 거의 비슷하지만 다른 점이 있습니다.
 */

/**
 * 어떤 오래된 브라우저에서는 HTMLCollection대신에 NodeList를 반환합니다.
 * getElementsByClassName()에서도요
 */

/**
 * 하지만 대개 getElementByClassName()메소드는 HTMLCollection을 반환하고
 * querySelectorAll()에서는 NodeList객체를 반환하게 됩니다.
 */

const myNodeList = document.querySelectorAll(".test");
console.log(myNodeList);
for (let i = 0; i < myNodeList.length; i++) {
  console.log(myNodeList[i]);
}

/**
 * 이제 NodeList와 HTMLCollection의 차이점에 대해서 설명하겠습니다.
 *
 * 둘은 모두 length 속성이 있고 element로 부터 extracted되어 진 것에 공통점이 있긴 합니다.
 *
 * 하지만 HTMLCollection은 name, id, index number등에 다 접근 가능하지만
 * NodeList는 오직 index number에만 접근 가능합니다.
 *
 * 또한 HTMLCoolection은 언제나 live collection으로 이 HTMLCollection객체를 수정하면
 * 즉각적으로 DOM객체가 바뀌게 되는 반면
 *
 * NodeList객체는 static collection으로 바뀌지 않습니다.
 */

/**
 * getElementByClassName(), getElementByTagName()은 HTMLCollection을 반환
 *
 * querySelectorAll()은 NodeList를 반환
 *
 * childNodes속성은 NodeList를 반환
 */
