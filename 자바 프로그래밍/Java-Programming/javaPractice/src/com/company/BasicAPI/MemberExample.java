package com.company.BasicAPI;

public class MemberExample {
    public static void main(String[] args) {
//        Member obj1 = new Member("blue");
//        Member obj2 = new Member("blue");
//        Member obj3 = new Member("red");
//
//        if(obj1.equals(obj2)) {
//            System.out.println("obj1과 obj2는 동일합니다.");
//        } else {
//            System.out.println("obj1과 obj2는 동일하지 않습니다.");
//        }
//
//        if(obj2.equals(obj3)) {
//            System.out.println("obj2과 obj3는 동일합니다.");
//        } else {
//            System.out.println("obj2과 obj3는 동일하지 않습니다.");
//        }

//        Member original = new Member("blue", "홍길동", "12345", new int[] {21, 22}, true);
//
//        Member cloned = original.getMember();
//
//        cloned.age[0] = 30;
//
//        for (int i : cloned.age) {
//            System.out.print(i + " ");
//        }
//        System.out.println();
//
//        for (int i : original.age) {
//            System.out.print(i + " ");
//        }

        Member original = new Member("홍길동", 25, new int[] {90, 90}, new Car("소나타"));

        Member cloned = original.getMember();
        cloned.scores[0] = 100;
        cloned.car.model = "그랜저";

        System.out.println("[복제 객체의 픽드값]");;
        System.out.println("name: " + cloned.name);
        System.out.println("age: " + cloned.age);
        System.out.print("scores: {");
        for(int i = 0; i < cloned.scores.length; i++) {
            System.out.print(cloned.scores[i]);
            System.out.print((i == (cloned.scores.length - 1)) ? "" : ",");
        }
        System.out.println("}");


        System.out.println("[원본 객체의 픽드값]");;
        System.out.println("name: " + original.name);
        System.out.println("age: " + original.age);
        System.out.print("scores: {");
        for(int i = 0; i < original.scores.length; i++) {
            System.out.print(original.scores[i]);
            System.out.print((i == (original.scores.length - 1)) ? "" : ",");
        }
        System.out.println("}");
    }
}

//[복제 객체의 픽드값]
//name: 홍길동
//age: 25
//scores: {100,90}
//[원본 객체의 픽드값]
//name: 홍길동
//age: 25
//scores: {90,90}