package com.company.Calculator;

public class CalculatorImpl_v2 extends CalculatorImpl_v1{
    int another;

    public CalculatorImpl_v2(int pre, int post, int another) {
        super(pre, post);
        this.another = another;
    }

    @Override
    public int plus() {
        int middleValue = super.plus();
        int finalValue = middleValue + this.another;
        return finalValue;
    }
}
