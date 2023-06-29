#include <stdio.h>

void binary(int number);

int main(void)
{
    binary(100);
    return 0;
}

void binary(int number)
{
    if (number > 0)
    {
        binary(number / 2);
        printf("%d ", number % 2);
    }
}