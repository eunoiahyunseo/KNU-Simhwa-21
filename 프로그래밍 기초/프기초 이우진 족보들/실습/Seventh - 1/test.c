#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{

    // char s1[30] = "The Little Prince";

    // char *ptr = malloc(sizeof(char) * 100);
    // strcpy(ptr, strtok(s1, " "));

    // // char *ptr = strtok(s1, " ");

    // while (ptr != NULL)
    // {
    //     printf("%s\n", ptr);
    //     ptr = strtok(NULL, " ");
    // }

    // printf("%s\n", ptr);
    // char *charPtr[100];

    // for (int i = 0; i < 3; i++)
    // {
    //     *(charPtr + i) = malloc(sizeof(char) * 100);
    //     gets(*(charPtr + i));
    // }

    // for (int i = 0; i < 3; i++)
    // {
    //     printf("%s %lu\n", *(charPtr + i), strlen(*(charPtr + i)));
    // }

    // char *s1 = "Hello world!";
    // char *s2 = malloc(sizeof(char) * 100);

    // s2[0] = 'K';
    // s2[1] = '\0';
    // s2[2] = 'G';
    // char *s3;
    // s3 = "Good";
    // // strcat(s2, s1);

    // printf("%s\n", s2);

    // char stmp[25] = "Java is o-o";
    // char lang[] = "language.";
    // printf("%s\n", strcat(stmp, lang));

    // char stmp[30] = "Java is object oriented";
    // char *Str = "CBCB";
    // strncpy(stmp, Str, strlen(Str));
    // int count = 0;

    // while (*(stmp + count) != '\0')
    // {
    //     printf("%c", *(stmp + count++));
    // }

    // count++;
    // printf("\n");

    // while (*(stmp + count) != '\0')
    // {
    //     printf("%c", *(stmp + count++));
    // }

    // char *delimiter = " ";
    // char str1[] = "C, C++ language are best";
    // char *ptoken;
    // strcpy(ptoken, strtok(str1, delimiter));

    // while (ptoken != NULL)
    // {
    //     printf("%s\n", ptoken);
    //     ptoken = strtok(NULL, delimiter);
    // }

    char line[81], ostr[80], name[30];
    int score1, score2;
    gets(line);

    sscanf(line, "%s %d %d", name, &score1, &score2);
    sprintf(ostr, "%s : %d+%d = %d\n", name, score1, score2, score1 + score2);
    puts(ostr);
    return 0;
}