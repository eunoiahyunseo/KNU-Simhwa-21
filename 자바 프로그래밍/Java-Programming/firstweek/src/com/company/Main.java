package com.company;

import com.company.Calculator.CalculatorImpl_v2;
import com.company.Thread.Sample;

import javax.swing.plaf.basic.BasicInternalFrameTitlePane;
import java.util.*;


public class Main {

    public static void main(String[] args)
    {
        List<Integer> list1 = new ArrayList<>();
        list1.add(1);
        list1.add(2);

        System.out.println(list1.get(0));

        Integer data_list[][] = {{1, 2, 3}, {4, 5, 6}};

        System.out.println(Arrays.toString(data_list[0]));

        System.out.println("========== Inner Class Example ==========");

//        InnerClass outer  = new InnerClass(20, "hyunsoe");
//        InnerClass.Inner_InnerClass inner = outer.new Inner_InnerClass(21, "hyunseo2");
//
//        System.out.println("outer age >> " +  outer.outerAge);
//        System.out.println("outer name >> " +  outer.outerName);
//
//        System.out.println("inner age >> " +  inner.innerAge);
//        System.out.println("inner name >> " +  inner.innerName);

        System.out.println("========== Static Inner Class Example ==========");
//        InnerClass outer  = new InnerClass(20, "hyunsoe");
//        InnerClass.Inner_InnerClass inner = new InnerClass.Inner_InnerClass(21, "hyunseo2");
//
//        System.out.println("outer age >> " +  outer.outerAge);
//        System.out.println("outer name >> " +  outer.outerName);
//
//        System.out.println("inner age >> " +  inner.innerAge);
//        System.out.println("inner name >> " +  inner.innerName);


//        MyInterface myClass = new MyInterface() {
//            static final int MyAge = 21;
//
//            @Override
//            public void doSomething() {
//                System.out.println("doSomething");
//            }
//        };
//
//        System.out.println(myClass.MyAge);
//        myClass.doSomething();


        CalculatorImpl_v2 calculator = new CalculatorImpl_v2(10, 20, 30);
        System.out.println("10 + 20 + 30 >> " + calculator.plus());
        System.out.println("20 - 10 >> " + calculator.execMinus(20, 10));


        System.out.println("========= multi Thread Example =========");
        for(int i = 0; i < 10; i++) {
            Thread t = new Sample(i);
            t.start();
        }

        System.out.println("main end.");
    }
}
