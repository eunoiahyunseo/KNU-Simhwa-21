package com.company.JComponent;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ComboActionEx extends JFrame {
    private String[] fruits = {"apple", "banana", "mango"};
    private ImageIcon[] images = {new ImageIcon("images/apple.jpg"),
                                new ImageIcon("images/banana.jpg"),
                                new ImageIcon("images/mango.jpg")};

    private JLabel imageLabel = new JLabel(images[0]);
    public ComboActionEx() {
        setTitle("콤보박스 활용 예제");
        Container c = getContentPane();
        c.setLayout(new FlowLayout());
        JComboBox<String> combo = new JComboBox<>(fruits);
        c.add(combo);
        c.add(imageLabel);

        combo.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JComboBox<String> cb = (JComboBox<String>) e.getSource();
                int index = cb.getSelectedIndex();
                imageLabel.setIcon(images[index]);
            }
        });

        setSize(300, 250);
        setVisible(true);

    }
    public static void main(String[] args) {
        new ComboActionEx();
    }
}
