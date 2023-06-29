#include <stdio.h>

int main(void)
{
    double number[3][3] = {0};

    printf("%lu\n", sizeof(number[0][0]));

    printf("%lu\n", sizeof(number[0] + 1));

    printf("%lu\n", sizeof(number[0]));

    return 0;
}