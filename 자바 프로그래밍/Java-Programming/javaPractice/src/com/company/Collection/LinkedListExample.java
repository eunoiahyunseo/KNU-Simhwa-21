package com.company.Collection;

import java.util.*;
public class LinkedListExample {
    public static void main(String[] args) {
        List<String> list1 = new ArrayList<>();
        List<String> list2 = new LinkedList<>();

        long startTime;
        long endTime;

        startTime = System.nanoTime();
        for(int i = 0; i < 10000; i++) {
            list1.add(0, String.valueOf(i));
        }

        endTime = System.nanoTime();
        System.out.println("ArrayList 걸린시간: " + (endTime - startTime) + " ns");

        startTime = System.nanoTime();
        for(int i = 0; i < 10000; i++) {
            list2.add(0, String.valueOf(i));
        }

        endTime = System.nanoTime();
        System.out.println("LinkedList 걸린시간: " + (endTime - startTime) + " ns");

    }
}

//ArrayList 걸린시간: 10401879 ns
//LinkedList 걸린시간: 3879617 ns