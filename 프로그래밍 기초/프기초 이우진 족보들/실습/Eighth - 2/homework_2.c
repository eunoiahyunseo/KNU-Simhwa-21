#include <stdio.h>
int sum;

void resetAcuumulateSum()
{
    extern int sum;
    sum = 0;
}

int accumulateSum(int num)
{
    extern int sum;
    sum += num;
    return sum;
}

int main(void)
{
    int value;
    while (1)
    {
        scanf("%d", &value);

        if (value == 0)
        {
            break;
        }

        if (value < 0)
        {
            printf("Total sum : %d\n", accumulateSum(0));
            resetAcuumulateSum();
        }
        else
        {
            accumulateSum(value);
        }
    }

    return 0;
}