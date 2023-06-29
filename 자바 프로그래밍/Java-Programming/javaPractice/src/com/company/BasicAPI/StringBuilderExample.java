package com.company.BasicAPI;

public class StringBuilderExample {
    public static void main(String[] args) {
        StringBuilder sb = new StringBuilder();

        sb.append("java ");
        sb.append("Program Study");
        System.out.println(sb.toString());

        sb.insert(4, "2");
        System.out.println(sb.toString());

        sb.setCharAt(4, '6');
        System.out.println(sb.toString());

        sb.replace(6, 13, "Book");
        System.out.println(sb.toString());

        sb.delete(4, 5);
        System.out.println(sb.toString());

        int length = sb.length();
        System.out.println("총문자수: " + length);

        String result = sb.toString();
        System.out.println(result);
    }
}

//java Program Study
//java2 Program Study
//java6 Program Study
//java6 Book Study
//java Book Study
//총문자수: 15
//java Book Study