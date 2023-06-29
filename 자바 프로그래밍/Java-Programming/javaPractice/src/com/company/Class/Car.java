package com.company.Class;

public class Car {
    private int speed;
    private boolean stop;

    public Car() {}

    public int getSpeed() {
        return speed;
    }

    public void setSpeed(int speed) {
        if(speed < 0) {
            this.speed = 0;
        } else {
            this.speed = speed;
        }
    }

    public boolean isStop() {
        return stop;
    }

    public void setStop(boolean stop) {
        this.stop = stop;
        this.speed = 0;
    }

    public static void main(String[] args) {
        Car myCar = new Car();

        myCar.setSpeed(-50);
        System.out.println("현재 속도: " + myCar.getSpeed());

        myCar.setSpeed(60);
        System.out.println("현재 속도: " + myCar.getSpeed());

        if(!myCar.isStop()) {
            myCar.setStop(true);
        }
        System.out.println("현재 속도: " + myCar.getSpeed());
    }
}

// 현재 속도: 0
// 현재 속도: 60
// 현재 속도: 0
