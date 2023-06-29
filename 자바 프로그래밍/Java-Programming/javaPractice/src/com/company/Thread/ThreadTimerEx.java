package com.company.Thread;

import javax.swing.*;
import java.awt.*;

public class ThreadTimerEx extends JFrame {
    public ThreadTimerEx() {
        super("Thread를 상속받은 타이머 스레드 예제");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.setLayout(new FlowLayout());

        // 타이머 값을 출력할 레이블 생성
        JLabel timerLabel = new JLabel();
        timerLabel.setFont(new Font("Gothic", Font.ITALIC, 80));
        c.add(timerLabel);

        TimerThread th = new TimerThread(timerLabel);
        setSize(250, 150);
        setVisible(true);
        th.start();
    }

    public static void main(String[] args) {
        new ThreadTimerEx();
    }
}
