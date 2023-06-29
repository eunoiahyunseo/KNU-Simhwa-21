#include <stdio.h>
// #include "mymacro.h"
#define MYSTR1 "2021113490"
#define MYSTR2 "이현서"

int main(void)
{
    // int input_value;
    // scanf("%d", &input_value);
    // printf("%d", SQ4(input_value));

    // int input_value;
    // scanf("%d", &input_value);
    // int ten_thousand = input_value / 10000;
    // input_value = input_value - ten_thousand * 10000;

    // int five_thousand = input_value / 5000;
    // input_value = input_value - five_thousand * 5000;

    // int thousand = input_value / 1000;
    // input_value = input_value - thousand * 1000;

    // int five_hundred = input_value / 500;
    // input_value = input_value - five_hundred * 500;

    // int hundred = input_value / 100;
    // input_value = input_value - hundred * 100;

    // int fifty = input_value / 50;
    // input_value = input_value - fifty * 50;

    // int ten = input_value / 10;
    // input_value = input_value - ten * 10;

    // int five = input_value / 5;
    // input_value = input_value - five * 5;

    // int one = input_value / 1;
    // input_value = input_value - one * 1;

    // printf("10000:%d\n", ten_thousand);
    // printf("5000:%d\n", five_thousand);
    // printf("1000:%d\n", thousand);
    // printf("500:%d\n", five_hundred);
    // printf("100:%d\n", hundred);
    // printf("50:%d\n", fifty);
    // printf("10:%d\n", ten);
    // printf("5:%d\n", five);
    // printf("1:%d\n", one);

    // int a = 5;
    // int b = 12;
    // int d = 20;
    // printf("%d", a + b++ - --d);
    printf("학번 = \"%-15s\"\n", MYSTR1);
    printf("이름 = \"%15s\"\n", MYSTR2);
    int a = 5;
    int b = 11;
    int d = 20;
    printf("%d", a % 4);
}