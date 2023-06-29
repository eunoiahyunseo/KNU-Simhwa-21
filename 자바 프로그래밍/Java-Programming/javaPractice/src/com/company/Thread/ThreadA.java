package com.company.Thread;

public class ThreadA {
    public static void main(String[] args) {
        // 앞에서 만든 쓰레드 B를 만든 후 start
        // 해당 쓰레드가 실행되면, 해당 쓰레드는 run메소드 안에서 모니터링 락을 획득
        ThreadB b = new ThreadB();
        b.start();

        // b에 대하여 동기화 블럭을 설정
        // 만약 main쓰레드가 아래의 블록을 위의 Thread보다 먼저 실행되었다면 wait을 하게 되면서 모니터링 락을 놓고 대기
        synchronized (b) {
            try {
                System.out.println("b가 완료될때까지 기다립니다.");
                b.wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            System.out.println("Total is: " + b.total);
        }
    }
}

//b가 완료될때까지 기다립니다.
//0을 더합니다.
//1을 더합니다.
//2을 더합니다.
//3을 더합니다.
//4을 더합니다.
//Total is: 10
