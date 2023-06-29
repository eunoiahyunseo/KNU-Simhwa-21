package com.company.Interface;

import sun.jvm.hotspot.debugger.cdbg.Sym;

public class RemoteControllerExample {
    public static void main(String[] args) {

        RemoteControl rc = new RemoteControl() {
            private int volume;
            @Override
            public void turnOn() {
                System.out.println("turnOn the TV");
            }

            @Override
            public void turnOff() {
                System.out.println("turnOff the TV");
            }

            @Override
            public void setVolume(int volume) {
                if(volume > RemoteControl.MAX_VOLUME) {
                    this.volume = RemoteControl.MAX_VOLUME;
                } else if(volume < RemoteControl.MIN_VOLUME) {
                    this.volume = RemoteControl.MIN_VOLUME;
                } else {
                    this.volume = volume;
                }
            }

            @Override
            public void getVolume() {
                System.out.println("volume >> " + volume);
            }
        };

        rc.setVolume(8);
        rc.getVolume();

    }
}

//TV를 켭니다.
//TV를 끕니다.