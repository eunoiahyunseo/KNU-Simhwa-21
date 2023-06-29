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

    for (int i = 0; i < count; i++)
    {
        for (int j = i; j < count; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}