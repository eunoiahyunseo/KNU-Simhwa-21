/**
 * 모든 자바스크립트의 객체들의 속성과 메소드들은 프로토타입에 의해 상속됩니다.
 */

function Person(first, last, age, eyecolor) {
  this.firstName = first;
  this.lastName = last;
  this.age = age;
  this.eyecolor = eyecolor;
}

const myFather = new Person("John", "Doe", 50, "blue");
const myMother = new Person("Sally", "Rally", 48, "green");

// 또한 우리는 객체 안에 새로운 속성을 추가할 떄 Person.nationality = "English"
// 와 같이 생성자에 붙여주면 안됩니다.

/**
 * 모든 자바스크립트의 객체들은 프로토타입에 의해 속성과 메소드를 상속받습니다.
 * Date객체는 Date.prototype을 상속받고
 * Array객체는 Array.prototype을 상속받습니다.
 */

// 또한 위에서 생성자로 속성 추가가 안된다고 했지만 아래와 같이 prototype을 통해 속성을 추가해 줄 수 있습니다.

Person.prototype.nationality = "English";

// 또한 새로운 메소드를 추가해 줄 수 있게 도와줍니다.

Person.prototype.name = function () {
  return this.firstName + " " + this.lastName;
};

// 또한 우리가 만든 prototype만을 바꿔야 하지 standard JavaScript object의 prototype을 바꿔서는 안됩니다.

/**
 * 이제 prototype에 대해 조금 깊게 생각해 보도록 하겠습니다.
 */

/**
 * JavaScript는 클래스라는 개념이 없고 객체 원형인 프로토타입을 이용하여 새로운 객체를 이용합니다. 이렇게 생성
 * 된 객체 역시 또 다른 객체의 원형이 될 수 있습니다.
 */

function Person2(name) {
  this.name = name || "혁준";
}

Person2.prototype.getName = function () {
  return this.name;
};

function Korean(name) {
  this.name = name;
}
Korean.prototype = Person2.prototype;

var kor1 = new Korean("현서");
// Korean생성자의 이름인데 Person prototype에 지정된 getName호출
console.log(kor1.getName());
// 부모 생성자를 호출 안했으니까 undefined
console.log(kor1.__proto__.getName.apply(kor1));

function Person3(name) {
  this.name = name || "혁준";
}

Person3.prototype.getName = function () {
  return this.name;
};

function Korean(name) {
  this.name = name;
}
//
Korean.prototype = new Person3("현서2");
Korean.prototype.getName = function () {
  return this.name + "헤헷";
};

const kor2 = new Korean("현서");
console.log(kor2.getName());
console.log(kor2.__proto__.__proto__.getName.apply(kor2));

function greate_grandfather() {
  this.eyes = "파란눈";
}

function grandfather() {
  this.height = "장신";
}

grandfather.prototype = new greate_grandfather();

function Person_(first, last, age, gender, interests) {
  this.first = first;
  this.last = last;
}

const person5 = new Person_("Bob", "Smith", 32, "male", [
  "music",
  "skiing",
]);

function 