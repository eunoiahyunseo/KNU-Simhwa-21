package com.company.Practice;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Practice2 {
    public static Scanner scanner;
    public static void main(String[] args) {
        String[] week = new String[] {"일", "월", "화", "수", "목", "금", "토"};

        scanner = new Scanner(System.in);
        while(true) {
            System.out.print("정수를 입력하세요 >> ");
            try {
                int inputValue = scanner.nextInt();
                if(inputValue == -1) {
                    break;
                }

                System.out.println(week[inputValue % week.length]);
            } catch(InputMismatchException e) {
                System.out.println("정수를 입력하지 않았습니다!!!");
                scanner.next();
                continue;
            }

        }
    }
}
