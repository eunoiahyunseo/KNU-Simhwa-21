#include <stdio.h>

void printStar(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main(void)
{
    int value;
    scanf("%d", &value);
    printStar(value);

    return 0;
}
