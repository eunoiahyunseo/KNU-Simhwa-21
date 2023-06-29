package com.company;

import java.util.Scanner;

public class Report1 {
    public static Scanner scanner;

    static void method1() {
        int StudentCount = 0, StudentSum = 0, StudentScore, StudentAvg = 0;

        scanner = new Scanner(System.in);
        while(true) {
            System.out.print("Enter grade: ");
            StudentScore = scanner.nextInt();
            if(StudentScore == -1) {
                // 만약에 0으로 나눌 수 없는 경우 더 입력받도록 아얘 while문에서 if문으로 분기처리
                if(StudentCount == 0) {
                    System.out.println("Please enter the score at least 1");
                    scanner.next();
                    continue;
                }
                break;
            }

            StudentSum += StudentScore;
            StudentCount++;
        }
        try {
            StudentAvg = StudentSum / StudentCount;
            System.out.println("Total of " + StudentCount + " student grades is " + (int) StudentSum);
            System.out.println("Class average is " + StudentAvg);
        } catch(ArithmeticException e) {
            System.out.println("0으로 나눌 수 없습니다.");
        } finally {
        }

    }

    static void method2() {
        int[] ScoreArr = new int[5];
        int ScannerIntValue;

        while(true) {
            System.out.print("Enter grade: ");
            scanner = new Scanner(System.in);
            ScannerIntValue = scanner.nextInt();


            if(ScannerIntValue == -1) {
                break;
            }

            if(ScannerIntValue > 100 || ScannerIntValue < 0) {
                System.out.println("Please enter the score again at range [0, 100]");
                continue;
            }

            switch (ScannerIntValue / 10) {
                case 10:
                case 9:
                    ScoreArr[0] += 1;
                    break;
                case 8:
                    ScoreArr[1] += 1;
                    break;
                case 7:
                    ScoreArr[2] += 1;
                    break;
                case 6:
                    ScoreArr[3] += 1;
                    break;
                default:
                    ScoreArr[4] += 1;
                    break;
            }
        }
        for(int index = 0; index < ScoreArr.length; index++) {
            System.out.println(((char)('A' + index) != 'E' ? (char)('A' + index) : "F") + ": " + ScoreArr[index]);
        }
    }

    static void method3() {
        System.out.print("금액을 입력하시오 : ");
        scanner = new Scanner(System.in);
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
            break;
        }
    }

    public static void main(String[] args) {
        System.out.println("================ method1() ================");
        method1();
        System.out.println("================ method2() ================");
        method2();
        System.out.println("================ method3() ================");
        method3();
    }
}

