package com.company.Interface.Car;

public class Car {
    Tire[] tires = {
            new HankookTire(),
            new HankookTire(),
            new HankookTire(),
            new HankookTire(),
    };

    void run() {
        for(Tire tire : tires) {
            tire.roll();
        }
    }

    public static void main(String[] args) {
        Car myCar = new Car();
        myCar.run();

        myCar.tires[0] = new KumhoTire();
        myCar.tires[1] = new KumhoTire();
        myCar.run();
    }
}

//한국 타이어가 굴러갑니다.
//한국 타이어가 굴러갑니다.
//한국 타이어가 굴러갑니다.
//한국 타이어가 굴러갑니다.
//금호 타이어가 굴러갑니다.
//금호 타이어가 굴러갑니다.
//한국 타이어가 굴러갑니다.
//한국 타이어가 굴러갑니다.