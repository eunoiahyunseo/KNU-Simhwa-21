#include <stdio.h>

int main(void)
{
    int sentinal;
    float sum = 0;
    int count = 0;
    float average;
    scanf("%d", &sentinal);
    while (sentinal > 0)
    {
        sum += sentinal;
        count += 1;
        scanf("%d", &sentinal);
    }

    average = sum / count;
    printf("%.2f\n", average);

    return 0;
}