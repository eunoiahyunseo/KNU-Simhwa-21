package com.company.Homework;

import java.util.Scanner;

public class Homework1 {
    public static void main(String[] args) {
        Scanner scanner;
        int StudentCount = 0, StudentSum = 0, StudentScore, StudentAvg = 0;

        while(true) {
            System.out.print("Enter grade: ");
            scanner = new Scanner(System.in);
            StudentScore = scanner.nextInt();
            if(StudentScore == -1) {
                // 만약에 0으로 나눌 수 없는 경우 더 입력받도록 if문으로 분기처리
                if(StudentCount == 0) {
                    System.out.println("Please enter the score at least 1");
                    continue;
                }
                break;
            }

            StudentSum += StudentScore;
            StudentCount++;
        }
        StudentAvg = StudentSum / StudentCount;
        System.out.println("Total of " + StudentCount + " student grades is " + (int) StudentSum);
        System.out.println("Class average is " + StudentAvg);
    }
}
