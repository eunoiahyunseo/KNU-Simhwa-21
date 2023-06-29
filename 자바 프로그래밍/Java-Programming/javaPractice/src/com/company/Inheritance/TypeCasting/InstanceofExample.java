package com.company.Inheritance.TypeCasting;

public class InstanceofExample {
    public static void method1(Parent parent) {
        if(parent instanceof Child) {
            Child child = (Child) parent;
            System.out.println("method1 - Child로 변환 성공");
        } else {
            System.out.println("method1 - Child로 변환되지 않음");
        }
    }

    public static void method2(Parent parent) {
        Child child = (Child) parent; // ClassCastException이 발생할 가능성이 있음
        System.out.println("method2 - Child로 변환 성공");
    }

    public static void main(String[] args) {
        Parent parentA = new Child();
        method1(parentA);
        method2(parentA);

        Parent parentB = new Parent();
        method1(parentB);
        method2(parentB);
    }
}

//method1 - Child로 변환 성공
//method2 - Child로 변환 성공
//method1 - Child로 변환되지 않음
//Exception in thread "main" java.lang.ClassCastException: com.company.Inheritance.TypeCasting.Parent cannot be cast to com.company.Inheritance.TypeCasting.Child
//	at com.company.Inheritance.TypeCasting.InstanceofExample.method2(InstanceofExample.java:14)
//	at com.company.Inheritance.TypeCasting.InstanceofExample.main(InstanceofExample.java:25)