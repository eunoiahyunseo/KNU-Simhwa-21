package com.company.Swing;

import javax.swing.*;
import java.awt.*;

public class Mypanel5 extends JPanel {
    public Mypanel5() {
        setBackground(Color.DARK_GRAY);

        setLayout(new FlowLayout());

        JCheckBox apple = new JCheckBox("사과");
        JCheckBox pear = new JCheckBox("배", true);
        JCheckBox cherry = new JCheckBox("체리");

        add(new JLabel("이름 "));
        add(new JTextField(20));
        add(new JLabel("학과 "));
        add(new JTextField("컴퓨터공학과", 20));
        add(new JLabel("주소 "));
        add(new JTextField("서울시 ...", 20));
        add(apple);
        add(pear);
        add(cherry);

        String[] fruits = {"apple", "banana", "kiwi", "mango", "pear"};
        JList<String> strList = new JList<>(fruits);
        add(strList);

        JTextArea textArea = new JTextArea("연습용", 4, 20);
        JScrollPane scroll = new JScrollPane(textArea);
        add(scroll);

        ImageIcon img = new ImageIcon("./img/img1.jpg");
        JLabel label = new JLabel(img);
        add(label);

    }
}
