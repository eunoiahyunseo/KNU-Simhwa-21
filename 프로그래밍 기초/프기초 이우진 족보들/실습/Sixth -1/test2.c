#include <stdio.h>

int add(int, int);
int main(void)
{
    int a = 2;
    int b = 4;
    int add_result = add(a, b);
    printf("%d\n", add_result);
    return 0;
}

int add(int value_1, int value_2)
{
    int add_value = value_1 + value_2;
    return add_value;
}