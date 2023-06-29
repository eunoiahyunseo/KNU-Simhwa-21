package com.company.Swing;

import javax.swing.*;
import java.awt.*;

public class MyFrame extends JFrame {
    JPanel containerArr[] = new JPanel[5];


    public MyFrame() {
        setTitle("300x300 스윙 프레임 만들기");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Container contentPane = getContentPane();
        contentPane.setBackground(Color.ORANGE);
        contentPane.setLayout(new GridLayout(5, 1, 5, 5));

        containerArr[0] = new Mypanel();
        containerArr[1] = new Mypanel2();
        containerArr[2] = new Mypanel3();
        containerArr[3] = new Mypanel4();
        containerArr[4] = new Mypanel5();

        contentPane.add(containerArr[0]);
        contentPane.add(containerArr[1]);
        contentPane.add(containerArr[2]);
        contentPane.add(containerArr[3]);
        contentPane.add(containerArr[4]);

        setSize(1000, 750);
        setVisible(true);
    }

    public static void main(String[] args) {
        new MyFrame();
    }

}
