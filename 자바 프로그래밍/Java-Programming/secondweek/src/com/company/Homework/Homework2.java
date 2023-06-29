package com.company.Homework;

import java.util.Scanner;

public class Homework2 {
    public static void main(String[] args) {
        Scanner scanner;
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
}
