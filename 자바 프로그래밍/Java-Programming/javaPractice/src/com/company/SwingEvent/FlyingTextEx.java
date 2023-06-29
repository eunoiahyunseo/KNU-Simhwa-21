package com.company.SwingEvent;

import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class FlyingTextEx extends JFrame {
    private JLabel la = new JLabel("HELLO");

    public FlyingTextEx()
    {
        super("상, 하, 좌, 우 키를 이용하여 텍스트 움직이기");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Container c = getContentPane();
        c.setLayout(null);
        c.addKeyListener(new MyKeyListener());

        la.setLocation(50, 50);
        la.setSize(100, 20);
        c.add(la);

        setSize(200, 200);
        setVisible(true);

        c.setFocusable(true);
        c.requestFocus();
    }

    public static void main(String[] args) {
        new FlyingTextEx();
    }

    class MyKeyListener extends KeyAdapter {
        public void keyPressed(KeyEvent e) {
            int keyCode = e.getKeyCode();
            switch(keyCode) {
                case KeyEvent.VK_UP:
                    la.setLocation(la.getX(), la.getY() - 10);
                    break;
                case KeyEvent.VK_DOWN:
                    la.setLocation(la.getX(), la.getY() + 10);
                    break;
                case KeyEvent.VK_LEFT:
                    la.setLocation(la.getX() - 10, la.getY());
                    break;
                case KeyEvent.VK_RIGHT:
                    la.setLocation(la.getX() + 10, la.getY());
                    break;
            }
        }
    }
}
