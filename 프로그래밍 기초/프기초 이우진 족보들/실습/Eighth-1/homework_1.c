#include <stdio.h>
#include <string.h>

int main(void)
{
    char code1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    char code2[] = "hknopijxyzqfgmvwulastbcrde ";

    char input[100];
    gets(input);

    for (int j = 0; j < strlen(input); j++)
    {
        int index = 0;
        for (int i = 0; i < strlen(code1); i++)
        {
            if (code1[i] == input[j])
            {
                index = i;
                char putchar = code2[index];
                input[j] = putchar;
                break;
            }
        }
    }

    printf("%s", input);

    return 0;
}