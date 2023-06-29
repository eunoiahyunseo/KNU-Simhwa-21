package com.company;

public class MyRect extends MyPoint{
    int w;
    int h;

    protected MyRect() {
        this.w = 200;
        this.h = 300;
    }

    @Override
    protected void disp() {
        super.disp();
        System.out.println(super.x);
        System.out.println("폭 = " + this.w + ", 높이 = " + this.h);
    }
}
