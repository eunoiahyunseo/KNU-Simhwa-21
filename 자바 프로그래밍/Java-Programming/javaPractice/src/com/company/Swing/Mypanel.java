package com.company.Swing;

import javax.swing.*;
import java.awt.*;

public class Mypanel extends JPanel {
    public Mypanel() {
        setBackground(Color.BLUE);
        setLayout(new FlowLayout());

        this.add(new JButton("열기"));
        this.add(new JButton("레드"));
        this.add(new JButton("닫기"));
    }
}
