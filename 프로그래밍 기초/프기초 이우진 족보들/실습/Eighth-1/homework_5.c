#include <stdio.h>

int main(void)
{

    int number = 3;
    int Array1[number][number];
    int Array2[number][number];
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            scanf("%d", &Array1[i][j]);
        }
    }

    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            scanf("%d", &Array2[i][j]);
        }
    }
    int count = 0;
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            if (Array1[i][j] != Array2[i][j])
            {
                count += 1;
                break;
            }
        }
    }
    if (count == 0)
    {
        printf("same");
    }
    else
    {
        printf("not same");
    }

    return 0;
}