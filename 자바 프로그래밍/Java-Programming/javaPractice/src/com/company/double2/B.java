package com.company.double2;

public class B {
    int field1;
    void method1() {}

    static int field2;
    static void method2() {}

    class C {
        void method() {
            field1 = 10;
            method1();

            field2 = 10;
            method2();
        }
    }

    static class D {
        void method() {
            // field1 = 10;
            // method1();

            field2 = 10;
            method2();
        }
    }
}
