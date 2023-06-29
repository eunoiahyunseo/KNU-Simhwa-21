// before가상 선택자
let beforeTag = document.createElement("div");
beforeTag.style.cssText = beforeTag.innerText = "";

// strongTag
let strongTag = document.querySelector("#js p > strong");
beforeTag.appendChild(strongTag);
// Click event 발생 시
document
  .getElementById("test1")
  .addEventListener("click", () => {
    // inline style뿐만 아니라 계산된 모든 css값을 가져온 대에서 style과 차이가 있다.
    const button = document.querySelector(
      "#js > button[id='test1']"
    );
    console.log(getComputedStyle(button));
  });
