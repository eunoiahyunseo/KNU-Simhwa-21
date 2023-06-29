#include <stdio.h>
#include <math.h>

int main(void)
{
    // unsigned short data = 0x4B;

    // unsigned short msk1 = 0x20;
    // printf("%d\n", msk1 & data);

    // unsigned short msk2 = 0x1C;
    // printf("%d\n", msk2 | data);

    // unsigned short msk3 = 0x05;
    // printf("%d\n", ~msk3 & data);

    // unsigned short msk4 = 0x0C;
    // printf("%d\n", msk4 ^ data);

    // int a, b;

    // scanf("%d %d", &a, &b);
    // if (a > 0 && b > 0)
    // {
    //     printf("%d", 1);
    // }
    // else if (a < 0 && b > 0)
    // {
    //     printf("%d", 2);
    // }
    // else if (a < 0 && b < 0)
    // {
    //     printf("%d", 3);
    // }
    // else if (a > 0 && b < 0)
    // {
    //     printf("%d", 4);
    // }

    // int a, b, c;
    // scanf("%d %d %d", &a, &b, &c);
    // double discriminate = pow(b, 2) - 4 * a * c;
    // double x = 0;
    // double y = 0;

    // if (a == 0)
    // {
    //     x = -((double)c / b);
    //     printf("%lf", x);
    // }
    // else
    // {
    //     if (discriminate > 0)
    //     {
    //         x = (-b + sqrt(discriminate)) / (double)(2 * a);
    //         y = (-b - sqrt(discriminate)) / (double)(2 * a);
    //         printf("%lf, %lf", x, y);
    //     }
    //     else if (discriminate == 0)
    //     {
    //         x = -b / (2 * a);
    //         printf("%lf", x);
    //     }
    //     else if (discriminate < 0)
    //     {
    //         printf("허근입니다");
    //     }
    // }

    // double x = 2.4;
    // double y = 3.9;

    // int iResult3 = (int)x + y;
    // printf("%d", iResult3);

    // double iResult4 = (int)x + y;
    // printf("%lf", iResult4);

    int number, divisor, limit, count = 0;

    printf("2부터 n(입력) 까지의 소수를 구하자. \n");
    printf("2보다 큰 상한 값 정수 n을 입력 >> ");
    scanf("%d", &limit);

    // printf("\n2부터 %d까지의 소수는 =============== \n", limit);

    //     for (number = 2; number <= limit; number++)
    //     {
    //         for (divisor = 2; number % divisor; divisor++)
    //             ;

    //         if (divisor == number)
    //         {
    //             printf("%5d%c", number, (++count % 10) ? ' ' : '\n');
    //         }
    //     }
    // }
    for (number = 2; number <= limit; number++)
    {
        for (divisor = 2; divisor <= number; divisor++)
        {
            if (!(number % divisor) && !(divisor == number))
            {
                break;
            }

            if (divisor == number)
            {
                printf("%5d %c", number, (++count % 5) ? ' ' : '\n');
            }
        }
        // }
        // int i, count = 0;
        // for (i = 1; i <= 10; i++)
        // {
        //     count++;
        //     printf("%d\n", i);
        // }
        // printf("count: %d\n", count);
        // printf("%d\n", i);
    }
}