#include <stdio.h>
#include <stdlib.h>

#include <string.h>

int main(void)
{

    char arr_1[1000];
    char arr_2[1000];
    char arr_3[1000];
    int arr_4[1000];
    char *arr_5[1000];
    char delimiter[] = " .,!\t\n";
    int count = 0;

    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            gets(arr_1);
        }
        else if (i == 1)
        {
            gets(arr_2);
        }
        else
        {
            gets(arr_3);
        }
    }

    char *ptoken = strtok(arr_1, delimiter);

    while (ptoken != NULL)
    {
        arr_4[count] = strlen(ptoken);
        arr_5[count] = ptoken;
        count += 1;
        ptoken = strtok(NULL, delimiter);
    }

    ptoken = strtok(arr_2, delimiter);

    while (ptoken != NULL)
    {
        arr_4[count] = strlen(ptoken);
        arr_5[count] = ptoken;
        count += 1;
        ptoken = strtok(NULL, delimiter);
    }

    ptoken = strtok(arr_3, delimiter);

    while (ptoken != NULL)
    {
        arr_4[count] = strlen(ptoken);
        arr_5[count] = ptoken;
        count += 1;
        ptoken = strtok(NULL, delimiter);
    }

    printf("%d ", count);

    int max = 0;
    for (int i = 0; i < count; i++)
    {
        if (arr_4[max] < arr_4[i])
        {
            max = i;
        }
    }

    printf("%s\n", arr_5[max]);

    return 0;
}