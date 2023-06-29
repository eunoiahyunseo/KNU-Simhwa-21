package com.company.Swing;

import javax.swing.*;
import java.awt.*;

public class Mypanel2 extends JPanel {
    public Mypanel2() {
        setBackground(Color.YELLOW);
        setLayout(new BorderLayout(10, 10));

        this.add(new JButton("열기"), BorderLayout.CENTER);
        this.add(new JButton("레드"), BorderLayout.NORTH);
        this.add(new JButton("닫기"), BorderLayout.SOUTH);
        this.add(new JButton("우"), BorderLayout.EAST);
        this.add(new JButton("좌"), BorderLayout.WEST);
    }
}
