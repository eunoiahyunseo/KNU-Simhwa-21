package com.company.Calculator;

public class CalculatorImpl_v1 implements Calculator_v1, Calculator_v2{
    public int pre;
    public int post;

    @Override
    public int plus() {
        return this.pre + this.post;
    }

    @Override
    public int execMinus(int pre, int post) {
        return Calculator_v1.super.execMinus(pre, post);
    }
    @Override
    public int multi(int pre, int post) {
        return pre * post;
    }

    public CalculatorImpl_v1(int pre, int post) {
        this.pre = pre;
        this.post = post;
    }
}
