#include <stdio.h>

void findSum(int data[], int n, int *sum)
{
    for (int i = 0; i < n; i++)
    {
        *sum += data[i];
    }
    printf("%d", *sum);
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

    int sum;
    findSum(intArr, value, &sum);

    return 0;
}