package com.company.BasicAPI;

public class ClassExample {
    public static void main(String[] args) {
        Car car = new Car("소나타");
        Class clazz1 = car.getClass();
        System.out.println(clazz1.getName());
        System.out.println(clazz1.getSimpleName());
        System.out.println(clazz1.getPackage().getName());

        try {
            Class clazz2 = Class.forName("com.company.BasicAPI.Car");
            System.out.println(clazz2.getName());
            System.out.println(clazz2.getSimpleName());
            System.out.println(clazz2.getPackage().getName());
        } catch(ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}

//com.company.BasicAPI.Car
//Car
//com.company.BasicAPI
//com.company.BasicAPI.Car
//Car
//com.company.BasicAPI
