package com.company.BasicAPI;

import java.io.IOException;

public class KeyboardToStringExample {
    public static void main(String[] args) throws IOException {
        byte[] bytes = new byte[100];

        System.out.print("입력: ");
        int readByteNo = System.in.read(bytes);

        String str = new String(bytes, 0, readByteNo - 1);
        System.out.println(str);
    }
}

//입력: Hello
//Hello