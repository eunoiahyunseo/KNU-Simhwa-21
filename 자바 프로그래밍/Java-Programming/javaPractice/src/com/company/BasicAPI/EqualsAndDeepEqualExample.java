package com.company.BasicAPI;

import java.util.Arrays;
import java.util.Objects;

public class EqualsAndDeepEqualExample {
    public static void main(String[] args) {
        Integer o1 = 1000;
        Integer o2 = 1000;

        System.out.println(Objects.equals(o1, o2));
        System.out.println(Objects.equals(o1, null));
        System.out.println(Objects.equals(null, o2));
        System.out.println(Objects.equals(null, null));
        System.out.println(Objects.deepEquals(o1, o2) + "\n");

        Integer[] arr1 = {1, 2};
        Integer[] arr2 = {1, 2};
        System.out.println(Objects.equals(arr1, arr2));
        System.out.println(Objects.deepEquals(arr1, arr2));
        System.out.println(Arrays.deepEquals(arr1, arr2));
        System.out.println(Objects.equals(null, arr2));
        System.out.println(Objects.equals(arr1, null));
        System.out.println(Objects.equals(null, null));
    }
}

//true
//false
//false
//true
//true
//
//false
//true
//true
//false
//false
//true