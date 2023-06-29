package com.company.Exception;

public class ArrayIndexOutOfBoundsExceptionExample {
    public static void main(String[] args) {
        String data1 = args[0];
        String data2 = args[1];

        System.out.println("args[0]: " + data1);
        System.out.println("args[1]: " + data2);

    }
}

//Exception in thread "main" java.lang.ArrayIndexOutOfBoundsException: 0
//	at com.company.Exception.ArrayIndexOutOfBoundsExceptionExample.main(ArrayIndexOutOfBoundsExceptionExample.java:5)