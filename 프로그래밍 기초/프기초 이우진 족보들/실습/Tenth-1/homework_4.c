#include <stdio.h>

int main(void)
{
    int value1, value2;
    int resultSum = 0;
    int intArray[100][100] = {0};
    scanf("%d %d", &value1, &value2);

    for (int i = 0; i < value1; i++)
    {
        for (int j = 0; j < value2; j++)
        {
            scanf("%d", &intArray[i][j]);
        }
    }

    for (int i = 0; i < value1; i++)
    {
        int sum = 0;
        for (int j = 0; j < value2; j++)
        {
            sum += intArray[i][j];
        }
        resultSum += sum;
        printf("%d\n", sum);
    }
    printf("%d\n", resultSum);

    return 0;
}