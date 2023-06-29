package com.company;

public class InnerClass {
    int outerAge;
    String outerName;
    InnerClass(int age, String name) {
        this.outerAge = age;
        this.outerName = name;
    }

//    public class Inner_InnerClass {
//        int innerAge;
//        String innerName;
//
//        Inner_InnerClass(int age, String name) {
//            this.innerAge = age;
//            this.innerName = name;
//        }
//    }

     public static class Inner_InnerClass {
        int innerAge;
        String innerName;

        Inner_InnerClass(int age, String name) {
            this.innerAge = age;
            this.innerName = name;
        }
    }
}
