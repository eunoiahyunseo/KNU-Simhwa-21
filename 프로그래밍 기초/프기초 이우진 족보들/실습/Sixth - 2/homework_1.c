#include <stdio.h>

int main(void)
{
    int arr[100];
    while (1)
    {
        int count = 0;
        for (int i = 0; i < 3; i++)
        {
            scanf("%d", &arr[i]);
            if (arr[i] == 0)
            {
                count += 1;
            }
            else
            {
                continue;
            }
        }
        if (count == 3)
        {
            break;
        }

        int min = arr[0];
        for (int i = 0; i < 3; i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
            }
        }

        int max = arr[0];
        for (int i = 0; i < 3; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }
        printf("%d ", max);
        printf("%d ", min);

        for (int i = 0; i < 3; i++)
        {
            if (arr[i] == max || arr[i] == min)
            {
                continue;
            }
            else
            {
                printf("%d\n", arr[i]);
            }
        }
    }
}