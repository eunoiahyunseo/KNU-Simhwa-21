package com.company.Calculator;

public interface Calculator_v1 {
    public int plus();

    default int execMinus(int pre, int post) {
        return pre - post;
    }

}
