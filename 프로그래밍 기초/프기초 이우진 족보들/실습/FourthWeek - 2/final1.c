#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void procNumber(char str[], int *num, int *sum);

int main(void)
{
    char str[255] = {0};
    int num = 0, sum = 0;

    fgets(str, 255, stdin);

    procNumber(str, &num, &sum);

    printf("%s\nNum = %d, Sum = %d", str, num, sum);
    return 0;
}

void procNumber(char str[], int *num, int *sum)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (isdigit(str[i]))
        {
            (*num)++;
            (*sum) += str[i] - '0';
        }

        if (islower(str[i]))
        {
            str[i] = toupper(str[i]);
        }
    }
}