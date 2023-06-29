package com.company.Iostream;

import java.io.FileReader;
import java.util.Scanner;

public class Practice1 {
    public static void main(String[] args) throws Exception{
        Scanner scanner = new Scanner(new FileReader("./test2.txt"));
        int count = 0;
        while(scanner.hasNext()) {
            String line = scanner.nextLine();
            System.out.println(++count + ": " + line);
        }
    }
}
