package com.company.Interface;

public class Example {
    public static void main(String[] args) {
        Music music = new Classic("캐논", 1732, "파햄밸");
        music.print();
        System.out.println(music.play());
    }
}
