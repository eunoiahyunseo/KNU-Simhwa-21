package com.company.Interface.defaultInterface;

public class Example {
    public static void main(String[] args) {
        ChildrenInterface ci1 = new ChildrenInterface() {
            @Override
            public void method3() {
                System.out.println("ChildInterface-method3()");
            }

            @Override
            public void method1() {
                System.out.println("ChildInterface-method1()");
            }
        };

        ci1.method1();
        ci1.method2();
        ci1.method3();

        System.out.println();

        ChildrenInterface2 ci2 = new ChildrenInterface2() {
            @Override
            public void method3() {
                System.out.println("ChildInterface2-method3()");
            }

            @Override
            public void method1() {
                System.out.println("ChildInterface2-method1()");
            }
        };

        ci2.method1();
        ci2.method2();
        ci2.method3();

        System.out.println();


        ChildrenInterface3 ci3 = new ChildrenInterface3() {
            @Override
            public void method2() {
                System.out.println("ChildInterface3-method2()");
            }

            @Override
            public void method3() {
                System.out.println("ChildInterface3-method3()");
            }

            @Override
            public void method1() {
                System.out.println("ChildInterface3-method1()");
            }
        };

        ci3.method1();
        ci3.method2();
        ci3.method3();
    }
}

//ChildInterface-method1()
//ParentInterface-method2()
//ChildInterface-method3()
//
//ChildInterface2-method1()
//ChildrenInterface2-method2()
//ChildInterface2-method3()
//
//ChildInterface3-method1()
//ChildInterface3-method2()
//ChildInterface3-method3()