package com.company.Interface;

public abstract class Music implements Payable{
    String name;
    int year;

    public Music(String name, int year) {
        this.name = name;
        this.year = year;
    }

    public String getName() {
        return this.name;
    }

    public int getYear() {
        return this.year;
    }

    public abstract void print();

    @Override
    public abstract String play();
}
