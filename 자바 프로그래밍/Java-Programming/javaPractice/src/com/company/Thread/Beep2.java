package com.company.Thread;

import java.awt.*;

public class Beep2 {
    public static void main(String[] args) {
        Thread th = new BeepTask();
        th.start();
        for(int i = 0; i < 5; i++) {
            System.out.println("띵");
            try {
                Thread.sleep(1000);
            } catch(Exception e) {

            }
        }
    }


}
class BeepTask extends Thread {
    @Override
    public void run() {
        Toolkit toolkit = Toolkit.getDefaultToolkit();
        for(int i = 0; i < 5; i++) {
            toolkit.beep();
            System.out.println("beep");
            try {
                Thread.sleep(1000);
            } catch(Exception e) {

            }
        }
    }
}

