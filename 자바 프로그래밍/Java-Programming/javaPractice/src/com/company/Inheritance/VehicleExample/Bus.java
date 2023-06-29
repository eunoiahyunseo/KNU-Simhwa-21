package com.company.Inheritance.VehicleExample;

public class Bus extends Vehicle {
    @Override
    public void run() {
        System.out.println("버스가 달립니다.");
    }

//    @Override
//    public void run() {
//        super.run();
//    }
}
