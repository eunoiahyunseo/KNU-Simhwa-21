package com.company.BasicAPI;

import java.util.Objects;

public class NullExample {
    public static void main(String[] args) {
        String str1 = "홍길동";
        String str2 = null;

        System.out.println(Objects.requireNonNull(str1));

        try {
            String name = Objects.requireNonNull(str2);
        } catch(NullPointerException e) {
            System.out.println(e.getMessage());
        }

        try {
            String name = Objects.requireNonNull(str2, "이름이 없습니다.");
        } catch(NullPointerException e){
            System.out.println(e.getMessage());
        }

        try {
            String name = Objects.requireNonNull(str2, () -> "이름이 없다니깐요.");
        } catch(NullPointerException e) {
            System.out.println(e.getMessage());
        }
    }
}

//홍길동
//null
//이름이 없습니다.
//이름이 없다니깐요.