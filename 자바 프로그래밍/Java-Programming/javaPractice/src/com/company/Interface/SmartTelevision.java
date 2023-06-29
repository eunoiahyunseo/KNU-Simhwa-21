package com.company.Interface;

public class SmartTelevision implements RemoteControl, Searchable{
    private int volume;

    public SmartTelevision(int volume) {
        this.volume = volume;
    }

    @Override
    public void turnOn() {
        System.out.println("TV를 켭니다.");
    }

    @Override
    public void turnOff() {
        System.out.println("TV를 끕니다.");
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
    }

    @Override
    public void setMute(boolean mute) {
        RemoteControl.super.setMute(mute);
    }

    @Override
    public void search(String url) {
        System.out.println(url + "을 검색합니다.");
    }

    public static void main(String[] args) {
        RemoteControl rc = null;
        rc = new SmartTelevision(5);
        rc.getVolume();

        Searchable searchable = null;
        searchable = new SmartTelevision(5);
        searchable.search("http://localhost:4000");
    }
}
