package com.company;

public class MyPoint {
    public int x, y;
    protected MyPoint() {
        x = 100;
        y = 200;
    }
    protected void disp() {
        System.out.println("점(x, y)=(" + x + ", " + y + ")");
    }
}
