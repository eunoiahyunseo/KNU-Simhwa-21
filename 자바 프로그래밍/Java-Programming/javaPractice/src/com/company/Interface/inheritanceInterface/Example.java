package com.company.Interface.inheritanceInterface;

public class Example {
    public static void main(String[] args) {
        ImplementaionC impl = new ImplementaionC();

        InterfaceA ia = impl;
        ia.methodA();
        System.out.println();

        InterfaceB ib = impl;
        ib.methodB();
        System.out.println();

        InterfaceC ic = impl;
        ic.methodA();
        ic.methodB();
        ic.methodC();
    }
}

//ImplementationC-methodA() 실행
//
//ImplementationC-methodB() 실행
//
//ImplementationC-methodA() 실행
//ImplementationC-methodB() 실행
//ImplementationC-methodC() 실행