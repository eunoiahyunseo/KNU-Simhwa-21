#include <stdio.h>

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

    int min = intArray[0][0];
    for (int i = 0; i < value1; i++)
    {
        for (int j = 0; j < value2; j++)
        {
            if (intArray[i][j] < min)
            {
                min = intArray[i][j];
            }
        }
    }

    printf("%d", min);

    return 0;
}
