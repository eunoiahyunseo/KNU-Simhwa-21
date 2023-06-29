package com.company.Swing;

import javax.swing.*;
import java.awt.*;

public class Mypanel4 extends JPanel {
    public Mypanel4() {
        setBackground(Color.GRAY);
        setLayout(null);

        JLabel la = new JLabel("Hello, Press Buttons!");
        la.setLocation(130, 50);
        la.setSize(200, 20);
        add(la);

        for(int i = 1; i <= 9; i++) {
            JButton b = new JButton(Integer.toString(i));
            b.setLocation(i * 15, i * 15);
            b.setSize(50, 20);
            add(b);
        }
    }
}
