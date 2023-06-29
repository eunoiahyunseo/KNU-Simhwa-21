#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define type(x) _Generic((x),                                      \
                         _Bool                                     \
                         : "_Bool", unsigned char                  \
                         : "unsigned char",                        \
                           char                                    \
                         : "char", signed char                     \
                         : "signed char",                          \
                           short int                               \
                         : "short int", unsigned short int         \
                         : "unsigned short int",                   \
                           int                                     \
                         : "int", unsigned int                     \
                         : "unsigned int",                         \
                           long int                                \
                         : "long int", unsigned long int           \
                         : "unsigned long int",                    \
                           long long int                           \
                         : "long long int", unsigned long long int \
                         : "unsigned long long int",               \
                           float                                   \
                         : "float", double                         \
                         : "double",                               \
                           long double                             \
                         : "long double", char *                   \
                         : "char *",                               \
                           void *                                  \
                         : "void *", int *                         \
                         : "int *",                                \
                           default                                 \
                         : "unknown")

#define COUNT 10

int compare(const void *a, const void *b);
void swap(int *value_1, int *value_2);
void allocMemory(void **ptr, int size);

int main(void)
{

    // char arr[COUNT][20] = {"C-Language",
    //                        "Python",
    //                        "Java",
    //                        "Php",
    //                        "jQuery",
    //                        "API",
    //                        "MFC",
    //                        "Unity",
    //                        "C#",
    //                        "Jsp"};

    // qsort(arr, COUNT, sizeof(arr[0]), compare);

    // for (int i = 0; i < COUNT; i++)
    // {
    //     printf("%2d번 : %s\n", i + 1, arr[i]);
    // }

    // printf("\n");

    // int arr_[COUNT] = {5, 9, 2, 7, 10, 3, 6, 4, 8, 1};
    // for (int i = 0; i < COUNT; i++)
    // {
    //     for (int j = 0; j < COUNT - i - 1; j++)
    //     {
    //         if (arr_[j] > arr_[j + 1])
    //             swap(&arr_[j], &arr_[j + 1]);
    //     }
    // }

    // for (int i = 0; i < COUNT; i++)
    // {
    //     printf("arr_[%2d] : %d\n", i + 1, arr_[i]);
    // }

    // int numArr[][3] = {{1, 2, 3},
    //                    {4, 5, 6},
    //                    {7, 8, 9}};

    // int(*numArr_)[100] = &numArr;
    // printf("%d\n", sizeof(numArr_));
    // printf("%d\n", sizeof(numArr_[0]));

    // int *data[2] = {};
    // int int_arr_1[5] = {1, 2, 3, 4, 5};
    // int int_arr_2[5] = {6, 7, 8, 9, 10};
    // printf("%s\n", type(int_arr_1));
    // data[0] = int_arr_1;
    // data[1] = int_arr_2;

    // for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
    // {
    //     for (int j = 0; j < 5; j++)
    //     {
    //         printf("%2d ", *(*(data + i) + j));
    //     }
    //     printf("\n");
    // }
    // char *arr[3] = {"BlockDMask", "C Programming", "point_arr"};
    // // for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
    // // {
    // //     for (int j = 0; j < 5; j++)
    // //     {
    // //         printf("%d ", data[i][j]);
    // //     }
    // //     printf("\n");
    // // }

    // for (int i = 0; i < 3; i++)
    // {
    //     printf("arr[%d] -> %s\n", i + 1, arr[i]);
    // }

    // char *Char;
    // Char = malloc(sizeof(char) * 100);
    // printf("%p\n", Char);
    // Char = "asdf";
    // printf("%p\n", Char);

    // int arr_[5] = {1, 2, 3, 4, 5};
    // int(*arr)[5];
    // arr = &arr_;
    // int col = sizeof(*(arr + 0)) / sizeof(int);
    // for (int i = 0; i < col; i++)
    // {
    //     printf("%d ", *((*arr) + i));
    // }

    // char *charInputArr[3];
    // char inputString[100];

    // for (int i = 0; i < 3; i++)
    // {
    //     scanf("%s", inputString);
    //     int inputString_len = strlen(inputString) + 1;
    //     charInputArr[i] = malloc(sizeof(char) * inputString_len);
    //     strcpy(charInputArr[i], inputString);
    // }
    // printf("\n");

    // for (int i = 0; i < 3; i++)
    // {
    //     printf("%p\n", charInputArr[i]);
    // }

    // printf("\n");

    // for (int i = 0; i < 3; i++)
    // {
    //     printf("%s\n", charInputArr[i]);
    // }

    // for (int i = 0; i < 3; i++)
    // {
    //     free(charInputArr[i]);
    // }

    // char(*charArr)[100];
    // char inputString[3][100];

    // for (int i = 0; i < 3; i++)
    // {
    //     scanf("%s", inputString[i]);
    // }

    // charArr = inputString;
    // // for (int i = 0; i < 3; i++)
    // // {
    // //     printf("%s\n", inputString[i]);
    // // }

    // for (int i = 0; i < 3; i++)
    // {
    //     printf("%s\n", charArr[i]);
    // }

    long long *numPtr;

    allocMemory((void **)&numPtr, sizeof(long long));
    *numPtr = 100;
    printf("%lld\n", *numPtr);
    free(numPtr);
}

void allocMemory(void **ptr, int size)
{
    *ptr = malloc(size);
}

int compare(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b);
}

void swap(int *value_1, int *value_2)
{
    int temp;
    temp = *value_1;
    *value_1 = *value_2;
    *value_2 = temp;
}