#include <stdio.h>
#define getchar() getc(stdin);
#define putchar(_c) putc((_c), stdout);

int main(void)
{
    char input = getchar();
    putchar(input);

    return 0;
}