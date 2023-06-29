#include <stdio.h>
#include <stdlib.h>

void allocMemory(void *ptr, int size)
{
    ptr = malloc(size);
    printf("%p\n", ptr);
}

int main(void)
{
    long long *numPtr;

    allocMemory(numPtr, sizeof(long long));
    printf("%p\n", numPtr);

    return 0;
}