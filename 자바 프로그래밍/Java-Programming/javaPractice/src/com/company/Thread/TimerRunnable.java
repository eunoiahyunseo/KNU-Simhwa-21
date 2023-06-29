package com.company.Thread;

import javax.swing.*;


public class TimerRunnable implements Runnable{
    private JLabel timerLabel;
    public TimerRunnable(JLabel timerLabel) {
        this.timerLabel = timerLabel;
    }

    // 스레드 코드. run()이 종료하면 스레드 종료
    @Override
    public void run() {
        int n = 0; // 타이머 카운트 값
        while(true) {
            timerLabel.setText(Integer.toString(n));
            n++;
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                return;
            }
        }
    }
}
