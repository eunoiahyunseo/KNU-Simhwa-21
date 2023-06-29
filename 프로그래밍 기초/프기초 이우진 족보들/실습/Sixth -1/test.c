#include <stdio.h>
#include <stdlib.h>

void *allocMemory(void *ptr, int size)
{
    printf("%p\n", ptr);
    long long *longPtr = (long long *)ptr;
    longPtr = malloc(size);
    longPtr[0] = 1;
    printf("%lld\n", longPtr[0]);
    return longPtr;
}

void allocMemory_2(long long *ptr, int size)
{
    printf("%lld\n", *(ptr + 1));
    printf("%p\n", ptr);
    ptr = malloc(size * 2);
    *(ptr + 1) = 1;
    printf("%lld\n", *(ptr + 1));
}

void allocValue(long long *ptr)
{
    ptr[0] = 1;
}

void allocMemory_doublePointer(void **ptr, int size);

int main(void)
{

    // char a[5];
    // for (int i = 0; i < sizeof(a) / sizeof(char); i++)
    // {
    //     scanf("%c", a + i);
    // }
    // for (int i = 0; i < sizeof(a) / sizeof(char); i++)
    // {
    //     printf("%c", *(a + i));
    // }

    // int a[5];
    // a[1] = 5;
    // printf("%d\n", a[1]);

    // char name[20];
    // printf("> 너의 이름은? ");
    // scanf("%s", name);
    // // printf("%d\n", sizeof(name));
    // // printf("%d\n", sizeof(char));

    // // for (int i = 0; i < sizeof(name) / sizeof(char); i++)
    // // {
    // //     printf("%c", name[i]);
    // // }

    // printf("%s\n", name);

    // long long *numPtr;
    // void *alloc_numPtr = allocMemory(numPtr, sizeof(long long));
    // printf("%p\n", (long long *)alloc_numPtr);
    // printf("%lld\n", *(long long *)alloc_numPtr);

    long long *numPtr;
    allocMemory_2(numPtr, sizeof(long long));
    printf("%p\n", numPtr);
    printf("%lld\n", *(numPtr + 1));

    // long long numPtr;
    // allocValue(&numPtr);
    // printf("%lld\n", numPtr);

    // long long *numPtr;
    // allocMemory(numPtr, sizeof(long long));
}

void allocMemory_doublePointer(void **ptr, int size)
{
}
