package com.company.BasicAPI;

public class FinalizeExample {
    public static void main(String[] args) {
        Counter counter = null;
        for(int i = 1; i <= 50; i++) {
            counter = new Counter(i);
            counter = null;
            System.gc();
        }
    }
}


//4번 객체의 finalize()가 실행됨
//25번 객체의 finalize()가 실행됨
//27번 객체의 finalize()가 실행됨
//30번 객체의 finalize()가 실행됨
//33번 객체의 finalize()가 실행됨
//37번 객체의 finalize()가 실행됨
//42번 객체의 finalize()가 실행됨
//44번 객체의 finalize()가 실행됨
//49번 객체의 finalize()가 실행됨
//50번 객체의 finalize()가 실행됨
//48번 객체의 finalize()가 실행됨
//47번 객체의 finalize()가 실행됨
//46번 객체의 finalize()가 실행됨
//45번 객체의 finalize()가 실행됨
//43번 객체의 finalize()가 실행됨
//41번 객체의 finalize()가 실행됨
//40번 객체의 finalize()가 실행됨