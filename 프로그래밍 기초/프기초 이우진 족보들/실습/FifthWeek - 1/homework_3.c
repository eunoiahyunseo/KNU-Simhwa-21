#include <stdio.h>

int main(void)
{
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            printf("%d*%d=%d\t\t", 1 + (i - 1) * 3, j, (1 + (i - 1) * 3) * j);
            printf("%d*%d=%d\t\t", 2 + (i - 1) * 3, j, (2 + (i - 1) * 3) * j);
            printf("%d*%d=%d", 3 + (i - 1) * 3, j, (3 + (i - 1) * 3) * j);
            printf("\n");
        }
        printf("\n");
    }
}