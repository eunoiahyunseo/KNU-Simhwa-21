function Person(name) {
  this.name = name || "혁준";
}

Person.prototype.getName = function () {
  return this.name;
};

function Korean(name) {
  Person.prototype.constructor.apply(this, [name]);
}

Korean.prototype = new Person.prototype.constructor();

const kor6 = new Korean("현서");
console.log(kor6.getName());
