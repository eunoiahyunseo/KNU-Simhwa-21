/**
 * 우리는 JS로 HTML의 Element들을 조종할 수 있습니다.
 * 이를 하기 위해서는 우리는 element를 찾아야 하는데 이에는 여러가지 방법이 있습니다.
 * id로 찾거나,
 * tag name으로 찾거나,
 * class name으로 찾거나,
 * css selector로 찾거나,
 * html object collection으로 찾거나 이다.
 */

let element;
/**
 * DOM에서 HTML element를 찾는 가장 쉬운 방법은 element id를 이용하는 것입니다.
 * 아래 예제에서는 id="test1"인 html element를 찾았습니다.
 */
element = document.getElementById("test1");
// element에는 이제 객체로서 html element가 들어가게 됩니다.

/**
 * 또한 html tag name으로도 html element를 찾을 수 있습니다.
 */
element = document.getElementsByTagName("div");

// 또한 위의 예제에서 id="test1"인 모든 html element를 찾았는데 그 중 tagname이 div인 것을 찾고 싶다면
// 아래와 같이 하면 됩니다.
element = document.getElementById("test1");
element = element.getElementsByTagName("div");

// 또한 classname으로 html element를 찾을 수 있는데 아래와 같이 하면 된다.
element = document.getElementsByClassName("intro");
// 이는 class="intro"인 element를 찾은 것이다.

// 다음으로 css selector로도 html element를 찾을 수 있는데 아래와 같이 하면 된다.
element = document.querySelector("div#test1");
// 이러면 div이고 id="test1"인 html element를 찾게 됩니다.

// 마지막으로 html object collections으로 찾는 방법이 있습니다.
const x = document.forms;
for (let i = 0; i < x.length; i++) {
  console.log(x);
}

// for (const a of document.forms[0].elements.__proto__) {
//   console.log(a);
// }
