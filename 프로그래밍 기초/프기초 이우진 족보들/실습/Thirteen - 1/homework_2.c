#include <stdio.h>
#include <stdlib.h>

int *buildArr();

int findMin(int *inputIntArr);
int value;
int main(void)
{

    int i;
    FILE *fp_write;
    char outputName[100];
    gets(outputName);

    scanf("%d", &value);

    int *inputIntArr = buildArr();

    int minNumber = findMin(inputIntArr);

    fp_write = fopen(outputName, "w");

    fprintf(fp_write, "%d", minNumber);

    free(inputIntArr);

    return 0;
}

// 데이터의 입력
int *buildArr()
{
    int *intArr, i;
    intArr = malloc(sizeof(int) * value);

    for (i = 0; i < value; i++)
    {
        scanf("%d", intArr + i);
    }

    return intArr;
}

int findMin(int *inputIntArr)
{
    int i;
    int min = inputIntArr[0];

    for (i = 0; i < value; i++)
    {
        if (inputIntArr[i] < min)
        {
            min = inputIntArr[i];
        }
    }

    return min;
}