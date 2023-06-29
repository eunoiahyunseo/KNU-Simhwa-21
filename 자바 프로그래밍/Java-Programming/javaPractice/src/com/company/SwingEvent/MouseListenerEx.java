package com.company.SwingEvent;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class MouseListenerEx extends JFrame {
    private JLabel la = new JLabel("Hello");

    public MouseListenerEx() {
        setTitle("Mouse 이벤트 예제");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();
//        c.addMouseListener(new MyMouseListener());
        c.addMouseListener(new MyMouseAdapter());

        c.setLayout(null);
        la.setSize(50, 20);
        la.setLocation(30, 30);
        c.add(la);

        setSize(300, 200);
        setVisible(true);
    }

    public static void main(String[] args) {
        new MouseListenerEx();
    }

//    class MyMouseListener implements MouseListener {
//        @Override
//        public void mousePressed(MouseEvent e) {
//            int x = e.getX();
//            int y = e.getY();
//            la.setLocation(x, y);
//        }
//
//        @Override
//        public void mouseClicked(MouseEvent e) {
//
//        }
//
//
//        @Override
//        public void mouseReleased(MouseEvent e) {
//
//        }
//
//        @Override
//        public void mouseEntered(MouseEvent e) {
//
//        }
//
//        @Override
//        public void mouseExited(MouseEvent e) {
//
//        }
//    }

    class MyMouseAdapter extends MouseAdapter {
        @Override
        public void mousePressed(MouseEvent e) {
            int x = e.getX();
            int y = e.getY();
            la.setLocation(x, y);
        }
    }
}
