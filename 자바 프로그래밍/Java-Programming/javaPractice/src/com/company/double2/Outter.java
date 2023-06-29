package com.company.double2;

public class Outter {
    public void method2(int arg) {
        int localVariable = 1;
        // arg = 100 (x)
        // localVariable = 100 (x)
        class Inner {
            public void method() {
                int result = arg + localVariable;
            }
        }
    }
}
