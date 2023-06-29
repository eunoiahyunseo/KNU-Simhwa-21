#include <stdio.h>

int gcd(int max, int min)
{
    if (min == 0)
    {
        return max;
    }
    else
    {
        return gcd(min, max % min);
    }
}

int main(void)
{

    while (1)
    {
        int value1, value2;
        scanf("%d %d", &value1, &value2);
        if (value1 && value2)
        {
            printf("%d\n", gcd(value1, value2));
        }
        else
        {
            break;
        }
    }

    return 0;
}