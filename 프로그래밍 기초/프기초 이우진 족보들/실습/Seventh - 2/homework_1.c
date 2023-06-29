#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *arr[4];
    for (int i = 0; i < 4; i++)
    {
        arr[i] = malloc(sizeof(char) * 100);
        gets(arr[i]);
    }

    char *delimiter = " ";
    char *ptoken;

    for (int i = 0; i < 4; i++)
    {
        int sum = 0;
        ptoken = strtok(arr[i], delimiter);
        int count = 0;

        while (ptoken != NULL)
        {
            printf("%s ", ptoken);
            if (count == 1 || count == 2 || count == 3)
            {
                int number = atoi(ptoken);
                sum += number;
                count += 1;
            }
            else
            {
                count += 1;
            }
            ptoken = strtok(NULL, delimiter);
        }
        printf("%d\n", sum);
    }
}