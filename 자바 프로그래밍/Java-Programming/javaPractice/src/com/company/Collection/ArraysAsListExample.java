package com.company.Collection;

import java.util.Arrays;
import java.util.List;

public class ArraysAsListExample {
    public static void main(String[] args) {
        List<String> list1 = Arrays.asList("홍길동", "신용권", "감자바");
        for(String name : list1) {
            System.out.println(name);
        }

        Integer[] intList = new Integer[] {1, 2, 3};
        List<Integer> list2 = Arrays.asList(intList);
        for(int value : list2) {
            System.out.println(value);
        }
    }
}

//홍길동
//신용권
//감자바
//1
//2
//3