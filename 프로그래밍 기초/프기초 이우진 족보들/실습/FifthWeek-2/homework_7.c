#include <stdio.h>
int main()
{
    int cnt = 0;
    double array[100];

    while (1)
    {
        double x = 0;

        scanf("%lf", &x);

        if (x == 0)
        {
            break;
        }

        else
        {
            array[cnt] = x;
            cnt++;
        }
    }

    double total = 0;
    printf("%d\n", cnt);

    for (int i = 0; i < cnt; i++)
    {
        printf("%lf\n", total);
        total += array[i];
    }

    double average = total / (double)cnt;

    printf("%.1lf\n", average);

    for (int j = 0; j < cnt - 1; j++)
    {
        if (average > array[j])
        {
            printf("%.1lf ", (float)array[j]);
        }
    }
}