#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    FILE *fp;
    int value, seed, i;
    double sum;

    int *intArr;

    char inputArr[100];
    gets(inputArr);

    fp = fopen(inputArr, "r");

    fscanf(fp, "%d %d", &value, &seed);

    fclose(fp);

    // 시드 설정
    srand(seed);

    intArr = malloc(sizeof(int) * value);
    for (i = 0; i < value; i++)
    {
        intArr[i] = (rand() % 10);
    }

    for (i = 0; i < value; i++)
    {
        printf("%d ", intArr[i]);
        sum += intArr[i];
    }
    printf("\n");

    double avg = sum / value;
    printf("%.1lf", avg);

    free(intArr);

    return 0;
}