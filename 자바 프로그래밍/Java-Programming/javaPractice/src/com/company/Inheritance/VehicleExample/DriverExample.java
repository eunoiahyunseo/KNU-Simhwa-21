package com.company.Inheritance.VehicleExample;

public class DriverExample {
    public static void main(String[] args) {
        Driver driver = new Driver();

        Bus bus = new Bus();
        Taxi taxi = new Taxi();

        driver.drive(bus);
        driver.drive(taxi);
    }
}

//버스가 달립니다.
//택시가 달립니다.