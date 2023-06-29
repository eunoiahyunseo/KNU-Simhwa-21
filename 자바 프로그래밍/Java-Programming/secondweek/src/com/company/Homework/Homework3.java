package com.company.Homework;

import java.util.Scanner;

public class Homework3 {
    public static void main(String[] args) {
        System.out.print("금액을 입력하시오 : ");
        Scanner scanner = new Scanner(System.in);
        Integer money = scanner.nextInt(), moneyCount;
        while(money > 0) {
            moneyCount = money / 50000;
            if(moneyCount != 0) {
                System.out.println("오만원권 " + money / 50000 + "매");
            }
            money %= 50000;

            moneyCount = money / 10000;
            if(moneyCount != 0) {
                System.out.println("만원권 " + money / 10000 + "매");
            }
            money %= 10000;

            moneyCount = money / 1000;
            if(moneyCount != 0) {
                System.out.println("천원권 " + money / 1000 + "매");
            }
            money %= 1000;

            moneyCount = money / 100;
            if(moneyCount != 0) {
                System.out.println("백원 " + money / 100 + "개");
            }
            money %= 100;

            moneyCount = money / 50;
            if(moneyCount != 0) {
                System.out.println("오십원 " + money / 50 + "개");
            }
            money %= 50;

            moneyCount = money / 10;
            if(moneyCount != 0) {
                System.out.println("십원 " + money / 10 + "개");
            }
            money %= 10;
        }
    }
}
