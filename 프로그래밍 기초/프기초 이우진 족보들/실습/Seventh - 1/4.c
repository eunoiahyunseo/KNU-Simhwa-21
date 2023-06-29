#include <stdio.h>
#include <string.h>

int main(void)
{

    char *s1 = "Hello";
    char s2[10] = "Hello";

    s2[0] = 'A';
    printf("%c\n", s2[0]);
}