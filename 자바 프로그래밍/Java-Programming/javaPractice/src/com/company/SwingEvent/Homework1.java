package com.company.SwingEvent;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Homework1 extends JFrame {
    private JButton button1 = new JButton("Button1");
    private JButton button2 = new JButton("Button2");

    public Homework1() {
        super("Homework1");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Container c = getContentPane();
        c.setLayout(new FlowLayout());

        button1.addActionListener(new MyActionListener());
        button2.addActionListener(new MyActionListener());
        c.add(button1);
        c.add(button2);

        setSize(500, 300);
        setVisible(true);
    }

    public static void main(String[] args) {
        new Homework1();
    }

    class MyActionListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            JOptionPane.showMessageDialog(null, "You Pressed: " + e.getActionCommand());
        }
    }
}
