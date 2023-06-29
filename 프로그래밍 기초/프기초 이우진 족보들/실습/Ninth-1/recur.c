#include <stdio.h>

void printTri(int idx, int n)
{

    if (idx == n + 1)
    {
        return;
    }

    for (int i = 0; i < idx; i++)
    {
        printf("*");
    }
    printf("\n");

    printTri(idx + 1, n);

    for (int i = 0; i < idx; i++)
    {
        printf("*");
    }
    printf("\n");
}

int main(void)
{
    int value1, value2;
    scanf("%d %d", &value1, &value2);

    printTri(value1, value2);
    return 0;
}