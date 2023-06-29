#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

    while (1)
    {
        char arr_1[100];
        char arr_2[100];

        gets(arr_1);
        if ((strlen(arr_1) < 5 || strlen(arr_1) > 10))
        {
            printf("Retry\n");
            continue;
        }
        else
        {
            gets(arr_2);
            if (strlen(arr_2) < 5 || strlen(arr_2) > 10)
            {
                printf("Retry\n");
                continue;
            }
            else
            {
                if (strcmp(arr_1, arr_2) == 0)
                {
                    printf("Done");
                    break;
                }
                else
                {
                    printf("Retry\n");
                }
            }
        }
    }

    return 0;
}