#include <stdio.h>

int main()
{
    int a[5];
    int b[5];

    for (int i = 0; i < 5; i++)
    {
        int x;
        scanf("%d", &x);

        a[i] = x;
    }

    for (int j = 0; j < 5; j++)
    {
        int y;
        scanf("%d", &y);

        a[j] = y;
    }

    // int cnt = 5;

    // for (int k = 0; k < 5; k++)
    // {
    //     if (a[k] != b[k])
    //     {
    //         cnt--;
    //     }

    //     else
    //     {
    //         continue;
    //     }
    // }

    // if (cnt == 5)
    // {
    //     printf("%s", "same");
    // }

    // else
    // {
    //     printf("%s", "not same");
    // }

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", b[i]);
    }
}