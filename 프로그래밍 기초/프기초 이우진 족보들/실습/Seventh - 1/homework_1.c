#include <stdio.h>
#include <string.h>

int main(void)
{
    char *delimiter = " ";
    char *charArr[100];
    char line[81];
    int count = 0;
    gets(line);
    char *ptoken = strtok(line, delimiter);
    while (ptoken != NULL)
    {
        // printf("%s\n", ptoken);
        charArr[count] = ptoken;
        count += 1;
        ptoken = strtok(NULL, delimiter);
    }

    for (int i = 0; i < count; i++)
    {
        for (int j = strlen(charArr[i]) - 1; j >= 0; j--)
        {
            printf("%c", charArr[i][j]);
        }
        printf(" ");
    }

    return 0;
}