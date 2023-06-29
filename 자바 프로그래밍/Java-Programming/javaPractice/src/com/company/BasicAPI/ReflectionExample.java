package com.company.BasicAPI;

import java.lang.reflect.Constructor;

public class ReflectionExample {
    public static void main(String[] args) throws Exception {
        Class clazz = Class.forName("com.company.BasicAPI.Car");

        System.out.println("[클래스 이름]");
        System.out.println(clazz.getName());
        System.out.println();

        System.out.println("[생성자 정보]");
        Constructor[] constructors = clazz.getDeclaredConstructors();
        for(Constructor constructor : constructors) {
            System.out.print(constructor.getName() + "(");
            Class[] parameters = constructor.getParameterTypes();
            printParameters(parameters);
            System.out.println(")");
        }
    }

    private static void printParameters(Class[] parameters ){
        for(int i = 0; i < parameters.length; i++) {
            System.out.print(parameters[i].getName());
            if(i < parameters.length - 1) {
                System.out.print(",");
            }
        }
    }
}
//[클래스 이름]
//com.company.BasicAPI.Car
//
//[생성자 정보]
//com.company.BasicAPI.Car(java.lang.String)
