package com.company.double2.Anonymous;

public class AnonymousExample {
    public static void main(String[] args) {
        Anonymous anony = new Anonymous();

        anony.field.wake();

        anony.method1();

        anony.method2(new Person() {
            void study() {
                System.out.println("공부합니다.");
            }

            @Override
            void wake() {
                System.out.println("8시에 일어납니다.");
                this.study();
            }
        });
    }
}


//6시에 일어납니다.
//출근합니다.
//7시에 일어납니다.
//산책합니다.
//8시에 일어납니다.
//공부합니다.