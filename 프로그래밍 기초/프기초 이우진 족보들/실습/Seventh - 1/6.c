#include <stdio.h>
#include <string.h>

int main(void)
{
    char *delimiter = " ";
    char str1[] = "C, C++ language are best!";
    char *ptoken = strtok(str1, delimiter);
    while (ptoken != NULL)
    {
        printf("%s\n", ptoken);
        ptoken = strtok(NULL, delimiter);
    }
}