#include <stdio.h>

int main(void)
{
    int number = 4;
    int Array[number + 1][number + 1];
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            scanf("%d", &Array[i][j]);
        }
    }

    for (int i = 0; i < number; i++)
    {
        int sum = 0;
        for (int j = 0; j < number; j++)
        {
            sum += Array[i][j];
        }
        Array[i][number] = sum;
    }

    for (int i = 0; i < number; i++)
    {
        int sum = 0;
        for (int j = 0; j < number; j++)
        {
            sum += Array[j][i];
        }
        Array[number][i] = sum;
    }

    int sum = 0;
    for (int i = 0; i < number; i++)
    {
        sum += Array[i][number];
    }
    Array[number][number] = sum;

    for (int i = 0; i < number + 1; i++)
    {
        for (int j = 0; j < number + 1; j++)
        {
            printf("%4d", Array[i][j]);
        }
        printf("\n");
    }
}