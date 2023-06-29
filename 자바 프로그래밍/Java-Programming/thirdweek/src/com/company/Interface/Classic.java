package com.company.Interface;

public class Classic extends Music{
    String composer;

    public Classic(String name, int year, String composer) {
        super(name, year);
        this.composer = composer;
    }

    @Override
    public void print() {
        System.out.println("곡명=" + name + ", 연도=" + super.year + ", 작곡가=" + this.composer);
    }

    @Override
    public String play() {
        return getName() + "을 연주합니다";
    }
}
