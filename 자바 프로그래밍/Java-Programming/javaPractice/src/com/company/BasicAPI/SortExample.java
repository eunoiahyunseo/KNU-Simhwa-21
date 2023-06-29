package com.company.BasicAPI;

import java.util.Arrays;

public class SortExample {
    public static void main(String[] args) {
        int[] scores = {99, 97, 98};

        Arrays.sort(scores);
        for(int score : scores) {
            System.out.println(score);
        }

        System.out.println();

        String[] names = {"홍길동", "박동수", "김민수"};
        Arrays.sort(names);
        for(String name : names) {
            System.out.println(name);
        }

        System.out.println();

        Member[] members;
        members = new Member[] {
                new Member("홍길동"),
                new Member("박동수"),
                new Member("김민수")};
        Arrays.sort(members);
        for(Member member : members) {
            System.out.println(member.name);
        }
    }
}

//97
//98
//99
//
//김민수
//박동수
//홍길동
//
//김민수
//박동수
//홍길동