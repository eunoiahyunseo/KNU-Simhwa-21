#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stradd(char *dest, char *src)
{
    while (*dest)
    {
        dest++;
    }

    while (*src)
    {
        *dest = *src;
        src++;
        dest++;
    }

    *dest = '\0';
}

void allocMemory(void *ptr, int size)
{
    printf("%p\n", ptr);
    ptr = malloc(sizeof(long long) * 2);
    (char *)ptr = "Hello world!";
    for(int i = 0; i < sizeof(strlen((char *)ptr)))
}

int main(void)
{

    // int arr[3] = {1,
    //               2,
    //               3};

    // for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    // {
    //     scanf("%d", &arr[i]);
    // }

    // for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    // {
    //     printf("%p\n", &arr[i]);
    // }

    // for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    // {
    //     printf("%d\n", *(arr + i));
    // }

    // for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    // {
    //     printf("%p\n", arr + i);
    // }

    // char str1[4] = {"abc"};
    // char str2[4] = {"abc"};
    // if (str1 != str2)
    // {
    //     printf("doing well");
    // }

    // char str1[100] = "hello my name is\t";
    // char str2[] = "Psi";

    // printf("합치기 이전 : %s\n", str1);

    // stradd(str1, str2);

    // printf("합치기 이후 : %s\n", str1);
    // return 0;

    long long num = 100;
    long long *numPtr_2 = &num;
    allocMemory((void *)numPtr_2, sizeof(long long));
    return 0;

    // char name[20];
    // printf("> 너의 이름은? ");
    // scanf("%s", name);
    // for (int i = 0; name[i] != '\0'; i++)
    // {
    //     printf("%c", name[i]);
    // }

    // for (int i = 0; i < (strlen(name) / sizeof(char)) - 1; i++)
    // {
    //     printf("%c", name[i]);
    // }

    // printf("%lu\n", strlen(name));
    // return 0;

    // char line[81];
    // gets(line);
    // puts(line);
    // return 0;
}
