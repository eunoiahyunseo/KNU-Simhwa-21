#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{

    char arr_1[1000];
    char arr_2[1000];
    char arr_3[1000];
    char arr_4[1000];
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

    for (int i = 0; i < strlen(arr_1); i++)
    {
        if (ispunct(arr_1[i]))
        {
            arr_4[count] = arr_1[i];
            count += 1;
        }
    }

    for (int i = 0; i < strlen(arr_2); i++)
    {
        if (ispunct(arr_2[i]))
        {
            arr_4[count] = arr_2[i];
            count += 1;
        }
    }

    for (int i = 0; i < strlen(arr_3); i++)
    {
        if (ispunct(arr_3[i]))
        {
            arr_4[count] = arr_3[i];
            count += 1;
        }
    }

    printf("%d ", count);
    for (int i = 0; i < count; i++)
    {
        printf("%c", arr_4[i]);
    }
    return 0;
}