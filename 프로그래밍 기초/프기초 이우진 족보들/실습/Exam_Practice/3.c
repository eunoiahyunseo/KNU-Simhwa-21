//4번 문제
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char s1[100];
    char s2[100];
    char s3[100];
    char s4[100] = {
        0,
    };

    int cnt = 0;

    gets(s1);
    gets(s2);
    gets(s3);

    for (int i = 0; i < strlen(s1); i++)
    {

        if (ispunct(s1[i]) != 0)
        {
            s4[cnt] = s1[i];
            ++cnt;
        }
    }

    for (int i = 0; i < strlen(s2); i++)
    {

        if (ispunct(s2[i]) != 0)
        {
            s4[cnt] = s2[i];
            ++cnt;
        }
    }

    for (int i = 0; i < strlen(s3); i++)
    {

        if (ispunct(s3[i]) != 0)
        {
            s4[cnt] = s3[i];
            ++cnt;
        }
    }

    printf("%d ", cnt);

    for (int i = 0; i < strlen(s4); i++)
    {
        if (s4[i] != 0)
        {
            printf("%c", s4[i]);
        }
    }
}