#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char arr[80];
    gets(arr);

    char search_String[100];
    scanf("%s", search_String);
    int search_String_length = strlen(search_String);
    int count = 0;

    char *delimiter = " .,!?";

    char *ptoken = malloc(sizeof(char) * 100);
    strcpy(ptoken, strtok(arr, delimiter));

    while (ptoken != NULL)
    {
        int count_2 = 0;
        for (int i = 0; i < strlen(search_String); i++)
        {
            if (ptoken[i] == search_String[i] && count_2++)
                ;
        }

        if (count_2 == search_String_length)
        {
            count += 1;
        }
        ptoken = strtok(NULL, delimiter);
    }

    printf("%d", count);
    free(ptoken);
}