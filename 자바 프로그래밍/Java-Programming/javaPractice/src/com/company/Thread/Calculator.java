package com.company.Thread;

public class Calculator {
    private int memory;

    public int getMemory() {
        return memory;
    }

    synchronized void setMemory(int memory) {
        this.memory = memory;

        try {
            Thread.sleep(2000);
        } catch(InterruptedException e) {}
        System.out.println(Thread.currentThread().getName() + ":" + this.memory);
    }

    public static void main(String[] args) {
        Calculator calculator = new Calculator();

        User1 user1 = new User1();
        user1.setCalculator(calculator);
        user1.start();

        User2 user2 = new User2();
        user2.setCalculator(calculator);
        user2.start();
    }
}

class User1 extends Thread {
    private Calculator calculator;
    public void setCalculator(Calculator calculator) {
        this.setName("User1");
        this.calculator = calculator;
    }

    @Override
    public void run() {
        calculator.setMemory(100);
    }
}
class User2 extends Thread {
    private Calculator calculator;
    public void setCalculator(Calculator calculator) {
        this.setName("User2");
        this.calculator = calculator;
    }

    @Override
    public void run() {
        calculator.setMemory(50);
    }
}
