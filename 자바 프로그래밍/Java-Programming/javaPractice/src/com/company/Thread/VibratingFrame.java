package com.company.Thread;

import javax.swing.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.Random;

public class VibratingFrame extends JFrame implements Runnable {

    private Thread th; // 진동하는 스레드
    public VibratingFrame() {
        setTitle("진동하는 프레임 만들기");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(200, 200);
        setLocation(300, 300);
        setVisible(true);

        getContentPane().addMouseListener(new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
                if(!th.isAlive()) return;
                else th.interrupt();
            }
        });

        th = new Thread(this);
        th.start();
    }

    @Override
    public void run() { // 프레임의 진동을 일으키기 위해
        // 20ms마다 프레임의 위치를 렌덤하게 이동
        Random r = new Random();
        while(true) {
            try {
                Thread.sleep(20);
            } catch(InterruptedException e) {
                return; // 리턴하면 스레드 종료
            }
            int x = getX() + r.nextInt() % 5; // 새 위치 x
            int y = getY() + r.nextInt() % 5; // 새 위치 y
            setLocation(x, y);
        }
    }

    public static void main(String[] args) {
        new VibratingFrame();
    }
}
