package com.company.Calculator;

public interface Calculator_v2 {
    public int multi(int pre, int post);

    static int execMulti(int pre, int post) {
        return pre * post;
    }
}
