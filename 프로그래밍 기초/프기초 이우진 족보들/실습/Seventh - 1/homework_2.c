#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char line[81];
    gets(line);
    int num = atoi(line);
    printf("%d+%d=%d", num, 15, num + 15);
}