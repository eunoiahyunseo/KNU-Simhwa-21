#include <stdio.h>

int main(void)
{
    int number;
    int sum = 0;
    int min;

    scanf("%d", &number);

    int Array[number][number];

    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            scanf("%d", &Array[i][j]);
        }
    }

    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            sum += Array[i][j];
        }
    }

    min = Array[0][0];

    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            if (Array[i][j] < min)
            {
                min = Array[i][j];
            }
        }
    }

    printf("%d %d", sum, min);

    // for (int i = 0; i < number; i++)
    // {
    //     for (int j = 0; j < number; j++)
    //     {
    //         printf("%d", Array[i][j]);
    //     }
    //     printf("\n");
    // }

    return 0;
}