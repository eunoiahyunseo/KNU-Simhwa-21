package com.company.Collection;

import java.util.Objects;

public class Member {
    public String name;
    public int age;

    public Member(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public boolean equals(Object obj) {
        if(obj instanceof Member) {
            Member member = (Member) obj;
            return Objects.equals(member.name, name) && member.age == age;
        } else {
            return false;
        }
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, age);
    }
}
