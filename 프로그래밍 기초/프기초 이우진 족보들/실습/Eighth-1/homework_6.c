#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{

    char *charArr[100] = {0};

    int count = 0;
    char *quit = "quit";
    char inputChar[100];
    while (1)
    {
        scanf("%s", inputChar);
        if (strcmp(inputChar, quit))
        {
            charArr[count] = malloc(sizeof(char) * 100);
            strcpy(charArr[count], inputChar);
            count += 1;
        }
        else
        {
            break;
        }
    }

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (strcmp(charArr[j], charArr[j + 1]) > 0)
            {
                char *temp = charArr[j];
                charArr[j] = charArr[j + 1];
                charArr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        printf("%s\n", charArr[i]);
    }
}