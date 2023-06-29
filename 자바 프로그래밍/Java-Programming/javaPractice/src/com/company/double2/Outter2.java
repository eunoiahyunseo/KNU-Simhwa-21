package com.company.double2;

public class Outter2 {
    String field = "Outter-field";

    void method() {
        System.out.println("Outter-method");
    }

    class Nested {
        String field = "Nested-field";

        void method() {
            System.out.println("Nested-method");
        }

        void print() {
            // 중첩 객체 참조
            System.out.println(this.field);
            this.method();

            // 바깥 객체 참조
            System.out.println(Outter2.this.field);
            Outter2.this.method();
        }
    }

    public static void main(String[] args) {
        Outter2 outter = new Outter2();
        Outter2.Nested nested = outter.new Nested();
        nested.print();
    }
}

//Nested-field
//Nested-method
//Outter-field
//Outter-method