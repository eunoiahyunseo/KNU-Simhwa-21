package com.company.SwingEvent;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

public class MouseEventAllEx extends JFrame {
    private JLabel la = new JLabel(" Move Me");

    public MouseEventAllEx() {
        setTitle("MouseListener와 MouseMotionListener 예제");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Container c = getContentPane();
        MyMouseListener listener = new MyMouseListener();

        c.addMouseListener(listener);
        c.addMouseMotionListener(listener);

        c.setLayout(null);

        la.setSize(80, 20);
        la.setLocation(100, 80);
        c.add(la);

        setSize(300, 200);
        setVisible(true);
    }

    public static void main(String[] args) {
        new MouseEventAllEx();
    }

    class MyMouseListener implements MouseListener, MouseMotionListener {

        @Override
        public void mouseClicked(MouseEvent e) { }

        @Override
        public void mousePressed(MouseEvent e) {
            la.setLocation(e.getX(), e.getY());
            setTitle("mousePressed(" + e.getX() + "," + e.getY() + ")");
        }

        @Override
        public void mouseReleased(MouseEvent e) {
            la.setLocation(e.getX(), e.getY());
            setTitle("mouseReleased(" + e.getX() + "," + e.getY() + ")");
        }

        @Override
        public void mouseEntered(MouseEvent e) {
            Component comp = (Component)e.getSource();
            comp.setBackground(Color.CYAN);
        }

        @Override
        public void mouseExited(MouseEvent e) {
            Component comp = (Component)e.getSource();
            comp.setBackground(Color.YELLOW);
            setTitle("mouseExited(" + e.getX() + "," + e.getY() + ")");
        }

        @Override
        public void mouseDragged(MouseEvent e) {
            la.setLocation(e.getX(), e.getY());
            setTitle("mouseDragged(" + e.getX() + "," + e.getY() + ")");

        }

        @Override
        public void mouseMoved(MouseEvent e) {
            la.setLocation(e.getX(), e.getY());
            setTitle("mouseMoved(" + e.getX() + "," + e.getY() + ")");
        }
    }
}
