#include <stdio.h>

int main(void)
{
    char line[81];
    gets(line);

    for (int i = 0; line[i] != '\0'; i++)
    {
        putchar(line[i]);
    }

    printf("\n");
}