package com.company.Interface;

import java.rmi.Remote;

public class Audio implements RemoteControl{
    private int volume;
    private boolean mute;

    @Override
    public void turnOn() {
        System.out.println("Audio를 켭니다.");
    }

    @Override
    public void turnOff() {
        System.out.println("Audio를 끕니다.");
    }

    @Override
    public void getVolume() {
        System.out.println("volume >> " + volume);
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
        System.out.println("현재 Audio 볼륨: " + volume);
    }

    @Override
    public void setMute(boolean mute) {
        this.mute = mute;
        if(mute) {
            System.out.println("Audio 무음 처리 합니다.");
        } else {
            System.out.println("Audio 무음 해재합니다.");
        }
    }

    public static void main(String[] args) {
        RemoteControl rc = null;

        rc = new Television();
        rc.turnOn();
        rc.turnOff();

        rc = new Audio();
        rc.turnOn();
        rc.turnOff();
        rc.setMute(true);

        RemoteControl.changeBattery();
    }
}


