#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int sum = 0;
    printf("%d ", argc - 1);
    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);
        sum += number;
    }
    printf("%d\n", sum);
}