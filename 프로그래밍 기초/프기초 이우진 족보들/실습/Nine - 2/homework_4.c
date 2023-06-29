#include <stdio.h>

void minMax(int data[], int n, int *min, int *max)
{
    *min = data[0];
    for (int i = 0; i < n; i++)
    {
        if (data[i] < *min)
        {
            *min = data[i];
        }
    }

    *max = data[0];
    for (int i = 0; i < n; i++)
    {
        if (data[i] > *max)
        {
            *max = data[i];
        }
    }

    printf("%d %d", *max, *min);
}

int main(void)
{

    int value;
    scanf("%d", &value);
    int intArr[value];

    for (int i = 0; i < value; i++)
    {
        scanf("%d", &intArr[i]);
    }
    int min, max;
    minMax(intArr, value, &min, &max);

    return 0;
}