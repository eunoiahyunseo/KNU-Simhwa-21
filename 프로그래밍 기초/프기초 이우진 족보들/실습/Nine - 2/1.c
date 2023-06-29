#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 3

void allocMemory(void *ptr, int size);

void allocMemory_(void **ptr, int size);

int main(void)
{
    // int *a = NULL;
    // printf("%p\n", a);

    // a = malloc(sizeof(int) * 100);
    // printf("%p\n", a);

    // 포인터 배열
    // int *intArr[3];
    // for (int i = 0; i < 3; i++)
    // {
    //     // 3x4 배열을 만들어 준다.
    //     intArr[i] = malloc(sizeof(int) * 4);
    // }

    // printf("%lu\n", sizeof(intArr));                 // 24
    // printf("%lu\n", sizeof(int *));                  // 8
    // printf("%lu\n", sizeof(intArr) / sizeof(int *)); // 3

    // printf("%lu\n", sizeof(intArr[0]));

    // int point[] = {1, 2, 3, 4, 5};
    // printf("%p\n", point);
    // printf("%p\n", &point[0]);

    // printf("%p\n", &point[1]);

    // printf("%lu\n", sizeof(point));
    // int *point_;
    // point_ = &point[0];

    // printf("%lu\n", sizeof(point_));  // int*
    // printf("%lu\n", sizeof(*point_)); // 이렇게 포인터를 사용하면 크기정보를 알 수 없다.

    // int Arr[] = {1, 2, 3, 4, 5};
    // int *intArr = malloc(sizeof(int) * 5);

    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%p ", &intArr[i]);
    // }

    // char *data[LENGTH] = {"가나다", "ABC", "포인터"};
    // for (int i = 0; i < 3; i++)
    // {
    //     printf("data[%d] >> %s\n", i, data[i]);
    // }

    // char charData[LENGTH][7] = {"A", "ABC", "BX"};
    // char(*data_)[7];
    // data_ = charData;

    // for (int i = 0; i < LENGTH; i++)
    // {
    //     printf("data_[%d] >> %s\n", i, data_[i]);
    // }

    // long long *numPtr = NULL;
    // allocMemory(numPtr, sizeof(long long));
    // *numPtr = 10;

    // long long *numPtr = NULL;
    // allocMemory_((void **)&numPtr, sizeof(long long));

    // *numPtr = 10;
    // printf("%lld\n", *numPtr);
    // free(numPtr);

    // char *pary[LENGTH];
    // for (int i = 0; i < LENGTH; i++)
    // {
    //     pary[i] = malloc(sizeof(char) * 100);
    //     scanf("%s", pary[i]);
    // }

    // for (int i = 0; i < LENGTH; i++)
    // {
    //     printf("pary[%d] >> %s\n", i, pary[i]);
    //     free(pary[i]);
    // }

    int i;
    char name[20], result[100];
    scanf("%s", name);

    for (i = 0; i < strlen(name); i++)
    {
        printf("%s\n", &name[i]);
    }

    for (i = 0; i < strlen(name); i++)
    {
        strcpy(result, "Header_");
        printf("%s\n", strcat(result, &name[i]));
    }

    return 0;
}

void allocMemory(void *ptr, int size)
{
    // ptr은 이 함수 안에서만 작동이 된다.
    ptr = malloc(size);
}

void allocMemory_(void **ptr, int size)
{
    *ptr = malloc(size);
}