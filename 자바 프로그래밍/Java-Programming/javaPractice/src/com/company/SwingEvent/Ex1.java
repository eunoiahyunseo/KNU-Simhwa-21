package com.company.SwingEvent;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Ex1 extends JFrame {
    public Ex1() {
        setTitle("Example");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();
        c.setLayout(new FlowLayout());
        JButton btn = new JButton("Action");
        btn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JButton b = (JButton)e.getSource();
                if(b.getText().equals("Action")) {
                    b.setText("액션");
                }
                else  {
                    b.setText("Action");
                }
                setTitle(b.getText());
            }
        });

        c.add(btn);

        setSize(300, 300);
        setVisible(true);
    }

    public static void main(String[] args) {
        new Ex1();
    }

    class MyTest implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            JButton b = (JButton)e.getSource();
            if(b.getText().equals("Action")) b.setText("액션");
            else b.setText("Action");
        }
    }
}
