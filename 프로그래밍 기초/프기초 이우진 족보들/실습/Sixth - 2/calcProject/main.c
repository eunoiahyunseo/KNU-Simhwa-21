#include "calc.h"
#include "print.h"

int main(void)
{
    CALC_DATA data1;
    data1.operand1 = 10;
    data1.operand2 = 20;

    add(&data1);
    print(&data1);

    CALC_DATA data2;
    data2.operand1 = 40;
    data2.operand2 = 15;

    add(&data2);
    print(&data2);
}