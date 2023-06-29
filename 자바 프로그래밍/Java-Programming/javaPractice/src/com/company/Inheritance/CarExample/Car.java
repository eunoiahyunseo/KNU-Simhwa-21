package com.company.Inheritance.CarExample;

public class Car {
    Tire[] tires = {
                    new Tire("앞왼쪽", 6),
                    new Tire("앞오른쪽", 2),
                    new Tire("뒤왼쪽", 3),
                    new Tire("뒤오른쪽", 4)
    };

    int run() {
        System.out.println("[자동차가 달립니다]");
        for(int i = 0; i < tires.length; i++) {
            if(tires[i].roll() == false) {
                stop();
                return i + 1;
            }
        }
        return 0;
    }

    void stop() {
        System.out.println("[자동차가 멈춥니다]");
    }
}
