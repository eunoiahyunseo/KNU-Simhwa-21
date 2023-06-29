package com.company.Scanner;

import java.util.Scanner;

public class ScannerExample {
    public static void main(String[] args) {
        Scanner a = new Scanner(System.in);
        System.out.println("in.next() >> " + a.next());
        System.out.println("in.next() >> " + a.next());
        System.out.println("in.nextInt() >> " + a.nextInt());
        System.out.println("in,nextDouble() >> " + a.nextDouble());
        System.out.println("in.nextBoolean() >> " + a.nextBoolean());
    }
}
