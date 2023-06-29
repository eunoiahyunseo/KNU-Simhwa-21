#include <stdio.h>

void printR(int number)
{
    int remain = number % 10;
    number = number / 10;
    if (number == 0)
    {
        printf("%d", remain);
    }
    else
    {
        printf("%d", remain);
        printR(number);
    }
}

int main(void)
{

    int number;
    scanf("%d", &number);
    printR(number);

    return 0;
}