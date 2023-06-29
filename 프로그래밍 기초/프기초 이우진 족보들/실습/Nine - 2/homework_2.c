#include <stdio.h>

int main(void)
{
    int value;
    scanf("%d", &value);

    int intArr[value];
    for (int i = 0; i < value; i++)
    {
        scanf("%d", &intArr[i]);
    }

    for (int i = 0; i < value; i++)
    {
        for (int j = i; j < value; j++)
        {
            printf("%d ", intArr[j]);
        }
        printf("\n");
    }

    return 0;
}