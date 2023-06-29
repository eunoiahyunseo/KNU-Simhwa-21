#include <stdio.h>

int main(void)
{

    int arr_1[5];
    int arr_2[5];
    int count = 0;

    for (int i = 0; i < sizeof(arr_1) / sizeof(int); i++)
    {
        scanf("%d", &arr_1[i]);
    }

    for (int i = 0; i < sizeof(arr_2) / sizeof(int); i++)
    {
        scanf("%d", &arr_2[i]);
    }

    for (int i = 0; i < sizeof(arr_1) / sizeof(int); i++)
    {
        if (arr_1[i] != arr_2[i])
        {
            printf("not same");
            count += 1;
            break;
        }
    }

    if (count == 0)
    {
        printf("same");
    }

    return 0;
}