#include <stdio.h>

int main(void)
{
    int number = 4;
    int Array[number][number];
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            scanf("%d", &Array[i][j]);
        }
    }

    int Array_T[number][number];
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            Array_T[j][i] = Array[i][j];
        }
    }

    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {

            printf("%4d", Array_T[i][j]);
        }

        printf("\n");
    }
}