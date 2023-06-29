package com.company.BasicAPI;

import java.util.Arrays;
import java.util.Objects;

public class Member implements Cloneable, Comparable<Member>{
        public String id;
        public String name;
        public int age;
        public int[] scores;
        public Car car;

        public Member(String name, int age, int[] scores, Car car) {
            this.name = name;
            this.age = age;
            this.scores = scores;
            this.car = car;
        }

        public Member(String name) {
            this.name = name;
        }

        @Override
        protected Object clone() throws CloneNotSupportedException{
            // 먼저 얕은 복사를 해서 name, age를 복제한다.
            Member cloned = (Member) super.clone();
            // scores를 깊은 복제한다.
            cloned.scores = Arrays.copyOf(this.scores, this.scores.length);
            // car를 깊은 복제한다.
            cloned.car = new Car(this.car.model);
            // 깊은 복제된 Member 객체를 리턴
            return cloned;
        }

        public Member getMember() {
            Member cloned = null;
            try {
                cloned = (Member) clone();
            } catch(CloneNotSupportedException e) {  }
            return cloned;
        }

        @Override
        public boolean equals(Object obj) {
            if(obj instanceof Member) {
                Member member = (Member) obj;
                if(id.equals(member.id)) {
                    return true;
                }
            }
            return false;
        }

        @Override
        public int hashCode() {
            return id.hashCode();
        }

    @Override
    public int compareTo(Member o) {
            // 이름 순으로
        return this.name.compareTo(o.name);
    }
}
