#include <stdio.h>

int main(void)
{

    double arr[1000];
    int count = 0;
    double sum = 0;

    while (1)
    {
        scanf("%lf", &arr[count]);

        if (arr[count] == 0)
        {
            break;
        }
        else
        {
            sum += arr[count];
            count += 1;
        }
    }
    double avg = sum / count;
    printf("%.1lf\n", avg);
    for (int i = 0; i < count; i++)
    {
        if (arr[i] < avg)
        {
            printf("%.1lf ", arr[i]);
        }
    }
    return 0;
}