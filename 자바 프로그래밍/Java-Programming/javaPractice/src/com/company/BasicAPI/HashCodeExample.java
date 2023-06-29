package com.company.BasicAPI;

import java.util.Objects;

public class HashCodeExample {
    public static void main(String[] args) {
        Student s1 = new Student(1, "홍길동;");
        Student s2 = new Student(1, "홍길동;");
        System.out.println(s1.hashCode());
        System.out.println(Objects.hashCode(s2));

        String a = "a";
        String b = "b";
        System.out.println(a.hashCode());
        System.out.println(b.hashCode());


    }

    static class Student {
        int sno;
        String name;

        Student(int sno, String name) {
            this.sno = sno;
            this.name = name;
        }

        @Override
        public int hashCode() {
            return Objects.hash(sno, name);
        }
    }
}

//1678652973
//1678652973