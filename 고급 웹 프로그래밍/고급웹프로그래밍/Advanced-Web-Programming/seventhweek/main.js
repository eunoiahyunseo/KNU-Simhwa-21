// $(document).ready(() => {
//   var myElement = $("#01");
//   myElement.text("Hello Korea!");
// });

// $(document).ready(() => {
//   $("button.hide").click(() => {
//     $("p").hide();
//   });

//   $("button.show").click(() => {
//     $("p").show();
//   });
// });

// $(document).ready(() => {
//   $("ans").hide();

//   $("p.q1").click(() => {
//     $("ans.q1").show();
//   });

//   $("ans.q1").click(function () {
//     $(this).hide();
//   });

//   $("p.q2").click(() => {
//     $("ans.q2").show();
//   });

//   $("ans.q2").click(function () {
//     $(this).hide();
//   });
// });

// var n = 0;
// $(document).ready(function () {
//   $("div.out").mouseenter(function () {
//     $("p:first", this).text("마우스 포인터 들어옴");
//     $("p:last", this).text(++n);
//   });

//   $("div.out").mouseleave(function () {
//     $("p:first", this).text("마우스 포인터 나감");
//     $("p:last", this).text("최종 횟수 : " + n);
//   });

//   $("div.out").mousedown(function () {
//     $("p:first", this).hide();
//     $("p:last", this).text("메시지 사라짐");
//   });

//   $("div.out").mouseup(function () {
//     $("p:first", this).show();
//     $("p:last", this).text("최종 횟수 : " + n);
//   });
// });

// $(document).ready(function () {
//   $("button.add").click(function () {
//     $("h1, h2, p").addClass("blue");
//     $("div").addClass("important");
//   });

//   $("button.remove").click(function () {
//     $("h1, h2, p").removeClass("blue");
//     $("div").removeClass("important");
//   });
// });

// $(document).ready(function () {
//   $("button").click(function () {
//     $("h1, h2, p, div").toggleClass("red");
//   });
// });

// $(document).ready(function () {
//   $("button").click(function () {
//     $("p").css({ "background-color": "yellow", "font-size": "200%" });
//   });
// });

// $(document).ready(function () {
//   var xWidth = 100;
//   var yHeight = 100;

//   $("div").click(function () {
//     $(this).width(xWidth).addClass("box");
//     $(this).height(yHeight).addClass("box");
//     xWidth = xWidth - 10;
//     yHeight = yHeight - 10;
//   });
// });

// $(document).ready(function () {
//   $("button.b1").click(function () {
//     $("img").animate({
//       width: "100px",
//     });
//   });
//   $("button.b2").click(function () {
//     $("img").animate({
//       width: "200px",
//     });
//   });
//   $("button.b3").click(function () {
//     $("img").animate({
//       width: "300px",
//     });
//   });
// });

// $(document).ready(function () {
//   $("#hide").click(function () {
//     $("img").hide("slow", function () {
//       console.log("hide is done");
//     });
//   });
// });

// $(document).ready(function () {
//   $("#panel").click(function () {
//     $("#panel").slideUp("fast");
//   });

//   $("#slide").click(function () {
//     $("#panel")
//       .css("color", "red")
//       .slideDown(2000)
//       .slideUp(6000)
//       .fadeTo("slow", 0.3);
//   });

//   $("#flip").click(function () {
//     $("#panel").slideToggle("slow");
//   });

//   $("#stop").click(function () {
//     $("#panel").stop();
//   });
// });

function move(obj, time) {
  $(obj).stop().animate(
    {
      left: 100,
      top: 0,
    },
    time
  );
}

function back(css) {
  $(css).stop().animate({
    left: 0,
    top: 0,
  });
}
