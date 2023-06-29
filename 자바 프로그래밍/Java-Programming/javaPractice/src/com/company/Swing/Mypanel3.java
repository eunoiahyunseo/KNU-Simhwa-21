package com.company.Swing;

import javax.swing.*;
import java.awt.*;

public class Mypanel3 extends JPanel {
    public Mypanel3() {
        setBackground(Color.GREEN);
        setLayout(new GridLayout(1, 10));

        for(int i = 0; i < 10; i++) {
            String text = Integer.toString(i);
            this.add(new JButton(text));
        }
    }
}
