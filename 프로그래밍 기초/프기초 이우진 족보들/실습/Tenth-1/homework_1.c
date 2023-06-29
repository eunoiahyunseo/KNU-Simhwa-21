#include <stdio.h>

void print1DArray(int d[], int n, int value);

int main(void)
{
    int value1, value2;
    int intArray[100][100] = {0};
    scanf("%d %d", &value1, &value2);

    for (int i = 0; i < value1; i++)
    {
        for (int j = 0; j < value2; j++)
        {
            scanf("%d", &intArray[i][j]);
        }
    }

    for (int j = 0; j < value1; j++)
    {
        for (int i = 0; i < value2; i++)
        {
            print1DArray(intArray[j], value2 - i, value2);
        }
    }

    return 0;
}

// value는 이제 배열의 길이
void print1DArray(int d[], int n, int value)
{
    for (int i = n; i > 0; i--)
    {
        printf("%d ", d[value - i]);
    }
    printf("\n");
}