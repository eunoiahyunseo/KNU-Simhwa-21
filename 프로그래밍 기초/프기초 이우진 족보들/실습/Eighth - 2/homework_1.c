#include <stdio.h>

int accumulateSum(int num)
{
    static int sum;
    sum += num;

    return sum;
}

int main(void)
{

    int value, sum;
    while (1)
    {

        scanf("%d", &value);
        if (value < 0)
        {
            break;
        }
        sum = accumulateSum(value);
        printf("value: %d, sum: %d\n", value, sum);
    }

    printf("Total sum : %d\n", accumulateSum(0));

    return 0;
}