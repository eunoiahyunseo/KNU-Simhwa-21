package com.company.Thread;

import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class TabAndThreadEx extends JFrame {
    private MyLabel bar = new MyLabel(100);
    public TabAndThreadEx(String title) {
        super(title);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.setLayout(null);
        bar.setBackground(Color.ORANGE);
        bar.setOpaque(true);
        bar.setLocation(20, 50);
        bar.setSize(300, 20);
        c.add(bar);

        c.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                bar.fill();
            }
        });

        setSize(350, 200);
        setVisible(true);

        c.setFocusable(true);
        ConsumerThread th = new ConsumerThread(bar);
        th.start();
    }
    public static void main(String[] args) {
        new TabAndThreadEx(
                "아무키나 빨리 눌러 바 채우기");
    }

}

class ConsumerThread extends Thread {
    private MyLabel bar;

    public ConsumerThread(MyLabel bar) {
        this.bar = bar;
    }

    @Override
    public void run() {
        while(true) {
            try {
                sleep(200);
                bar.consume();
            } catch(InterruptedException e) {
                return;
            }
        }
    }
}