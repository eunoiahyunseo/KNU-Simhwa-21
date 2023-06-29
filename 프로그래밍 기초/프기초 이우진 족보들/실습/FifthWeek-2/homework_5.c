#include <stdio.h>

int main(void)
{

    int arr[1000];
    int value;
    int count = 0;

    while (1)
    {
        scanf("%d", &value);
        if (value == 0)
        {
            break;
        }
        else
        {
            arr[count] = value;
            count += 1;
        }
    }
    int max = arr[0];
    int min = arr[0];
    for (int i = 0; i < count; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    printf("%d %d", max, min);
    return 0;
}