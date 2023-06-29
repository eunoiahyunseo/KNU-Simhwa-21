#include <stdio.h>
#include <math.h>
int main(void)
{
    float Celcius;
    scanf("%f", &Celcius);
    float value = (1.8) * Celcius + 32;
    int count = 1;

    while (1)
    {
        int guess;
        scanf("%d", &guess);
        if (guess > (int)(ceil(value)))
        {
            count += 1;
            printf("large\n");
        }
        else if (guess < (int)(ceil(value)))
        {
            count += 1;
            printf("small\n");
        }
        else
        {
            break;
        }
    }
    printf("correct %d", count);
}