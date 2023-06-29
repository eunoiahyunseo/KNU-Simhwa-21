package com.company.Exception;

public class NumberFormatException {
    public static void main(String[] args){
        String data1 = "100";
        String data2 = "a100";

        int value1 = Integer.parseInt(data1);
        int value2 = Integer.parseInt(data2);

        int result = value1 + value2;
        System.out.println(data1 + "+" + data2 + "-" + result);
    }
}

//Exception in thread "main" java.lang.NumberFormatException: For input string: "a100"
//	at java.lang.NumberFormatException.forInputString(NumberFormatException.java:65)
//	at java.lang.Integer.parseInt(Integer.java:580)
//	at java.lang.Integer.parseInt(Integer.java:615)
//	at com.company.Exception.NumberFormatException.main(NumberFormatException.java:9)