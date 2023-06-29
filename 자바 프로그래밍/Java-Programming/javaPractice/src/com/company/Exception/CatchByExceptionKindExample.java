package com.company.Exception;

public class CatchByExceptionKindExample {
    public static void main(String[] args) {
        try {
            String data1 = args[0];
            String data2 = args[1];

            int value1 = Integer.parseInt(data1);
            int value2 = Integer.parseInt(data2);
            int result = value1 + value2;

            System.out.println(data1 + "+" + data2 + "=" + result);
        } catch(ArrayIndexOutOfBoundsException e) {
            System.out.println("실행 매개값의 수가 부족합니다.");
            System.out.println("[실행 방법]");
            System.out.println("java CatchByExceptionKindExample num1 num2");
        } catch(java.lang.NumberFormatException e) {
            System.out.println("숫자로 변환할 수 없습니다.");
        } catch(Exception e) {
            System.out.println("실행에 문제가 있습니다.");
        } finally {
            System.out.println("다시 실행하세요");
        }
    }
}

//실행 매개값의 수가 부족합니다.
//[실행 방법]
//java CatchByExceptionKindExample num1 num2
//다시 실행하세요