package com.company.Interface.defaultInterface;

public interface ChildrenInterface2 extends ParentInterface{
    @Override
    default void method2() {
        System.out.println("ChildrenInterface2-method2()");
    }

    public void method3();
}
