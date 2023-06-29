#include <stdio.h>

int main(void)
{
    int count = 0;
    int arr[1000];
    while (1)
    {
        scanf("%d", &arr[count]);
        if (arr[count] == 0)
        {
            break;
        }
        else
        {
            count += 1;
        }
    }

    printf("%d\n", count);
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[count - i - 1]);
    }
    return 0;
}