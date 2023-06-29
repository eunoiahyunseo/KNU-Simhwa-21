#include <stdio.h>
#include <stdlib.h>

void changeTo_2(int *number)
{
    *number = 2;
}

void allocMemory(int *ptr, int size)
{
    ptr = malloc(size * 10);
    printf("%p\n", ptr);
    ptr[0] = 1;
    printf("%d\n", *ptr);
}

void allocMemory_version2(void **ptr, int size)
{
    *ptr = malloc(size);
}

void print2DArray(int (*arr)[5], int col, int row);

int main(void)
{
    // // int *numPtr = NULL;
    // // allocMemory(numPtr, sizeof(int));

    // // int a = 1;
    // // changeTo_2(&a);
    // // printf("%d\n", a);

    // long long *numPtr;
    // allocMemory_version2((void **)&numPtr, sizeof(long long));

    // *numPtr = 10;
    // printf("%lld\n", *numPtr);

    // int *numPtr2 = NULL;
    // printf("%p\n", numPtr2);
    // numPtr2 = malloc(sizeof(int));
    // printf("%p\n", numPtr2);
    // return 0;

    int(*numArr)[5];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", (*(numArr + i) + j));
        }
    }

    int col = sizeof(numArr[0]) / sizeof(int);
    int row = 2;
    print2DArray(numArr, col, row);
}

void print2DArray(int (*arr)[5], int col, int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
