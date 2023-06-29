package com.company;

public class MyCircle extends MyPoint{
    int r;
    protected MyCircle() {
        this.r = 50;
    }

    @Override
    protected void disp() {
        super.disp();
        System.out.println("반지름 r = " + this.r);
    }
}
