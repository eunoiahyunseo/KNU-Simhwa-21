#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *p;
    printf("%p\n", p);
    p = malloc(sizeof(char) * 100);
    printf("%p\n", p);
}
