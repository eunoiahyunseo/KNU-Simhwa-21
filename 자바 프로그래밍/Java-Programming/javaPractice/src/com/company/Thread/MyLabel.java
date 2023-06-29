package com.company.Thread;

import javax.swing.*;
import java.awt.*;

public class MyLabel extends JLabel {
    private int barSize = 0; // 바의 크기
    private int maxBarSize;

    public MyLabel(int maxBarSize) {
        this.maxBarSize = maxBarSize;
    }

    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        g.setColor(Color.MAGENTA);
        int width = (int)(((double)(this.getWidth()))
                /maxBarSize*barSize);
        if(width==0) return;
        g.fillRect(0, 0, width, this.getHeight());
    }


    synchronized void fill() {
        if(barSize == maxBarSize) {
            try {
                wait();
            } catch(InterruptedException e) { return; }
        }
        barSize++;
        repaint();
        notify();
    }

    synchronized void consume() {
        if(barSize == 0) {
            try {
                wait();
            } catch(InterruptedException e) {return; }
        }

        barSize--;
        repaint(); // 다시 바 그리기
        notify();
    }
}


