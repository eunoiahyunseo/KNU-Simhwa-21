#include <stdio.h>

int main(void)
{
    // int number, divisor, limit, count = 0;

    // scanf("%d", &limit);
    // printf("\n2부터 %d까지의 소수는 =================== \n", limit);
    // for (number = 2; number <= limit; number++)
    // {
    //     for (divisor = 2; number % divisor; divisor++)
    //         ;
    //     if (divisor == number)
    //     {
    //         printf("%5d%c", number, (++count % 10) ? ' ' : '\n');
    //     }
    // }

    // return 0;

    int number = 0;
    int i = 0;
    scanf("%d", &number);

    for (i = 0; i <= number; i++)
    {
        if (number % i == 0)
        {
            printf("%d\n", i);
        }
    }
}