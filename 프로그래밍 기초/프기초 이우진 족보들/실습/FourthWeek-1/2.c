#include <stdio.h>
#include <stdbool.h>
int main(void)
{
    // int i = 0;
    // int number = 0;

    // scanf("%d", &number);
    // for (i = 1; i <= number; i++)
    // {
    //     if (number % i == 0)
    //     {
    //         printf("%d\n", i);
    //     }
    // }

    // int number = 0;
    // int value = 0;
    // int numArr[100];
    // int sum = 0;

    // scanf("%d", &number);
    // for (int i = 0; i < number; i++)
    // {
    //     scanf("%d", &numArr[i]);
    // }

    // for (int i = 0; i < number; i++)
    // {
    //     sum += numArr[i];
    // }
    // printf("%d\n", sum);

    // int max = numArr[0];
    // for (int i = 0; i < number; i++)
    // {
    //     if (numArr[i] > max)
    //     {
    //         max = numArr[i];
    //     }
    // }

    // printf("%d\n", max);

    // int value = 0;
    // scanf("%d", &value);

    // for (int i = 1; i <= value; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         printf("%d", j);
    //     }

    //     for (int j = value - i; j > 0; j--)
    //     {
    //         printf("%c", '*');
    //     }
    //     printf("\n");
    // }

    int money = 0;

    scanf("%d", &money);

    if (money >= 0 && money <= 1000)
    {
        int sum = 0;
        printf("%d * 0.09 = %d\n", money, (int)(money * 0.09));
        sum += (int)(money * 0.09);
        printf("= %d", sum);
    }
    else if (money >= 1000 && money <= 4000)
    {
        int sum = 90;
        printf("1000 * 0.09 = 90\n");
        money -= 1000;
        printf("%d * 0.18 = %d\n", money, (int)(money * 0.18));
        sum += (int)(money * 0.18);
        printf("= %d", sum);
    }
    else if (money >= 4000 && money <= 8000)
    {
        int sum = 630;
        printf("1000 * 0.09 = 90\n");
        printf("3000 * 0.18 = 540\n");
        money -= 4000;
        printf("%d * 0.27 = %d\n", money, (int)(money * 0.27));
        sum += (int)(money * 0.27);
        printf("= %d", sum);
    }
    else if (money >= 8000)
    {
        int sum = 630 + 1080;
        printf("1000 * 0.09 = 90\n");
        printf("3000 * 0.18 = 540\n");
        printf("4000 * 0.27 = 1080\n");
        money -= 8000;
        printf("%d * 0.36 = %d\n", money, (int)(money * 0.36));
        sum += (int)(money * 0.36);
        printf("= %d", sum);
    }

    // do
    // {
    //     if (money >= 1000)
    //     {
    //         money -=
    //     }
    //     printf("")
    // } while (money > 0)

    // int number = 0;
    // scanf("%d", &number);

    // for (int i = 1; i <= number; i++)
    // {

    //     if (i % 3 != 0 && i % 2 != 0)
    //     {
    //         printf("%d ", i);
    //     }
    // }
}