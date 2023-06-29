#include <stdio.h>
#include <stdlib.h>

void afterString(char s[], char substr[], char res[])
{
    int start = 10;
    // afterString(str, "stu", res); 호출했을 때 i am a student에서 substr로 넘겨준 stu의 마지막 글자 u위치가 10

    // int i = start;
    // while (s[i] != NULL)
    // {
    //     res[i - start] = s[i++];
    // }
    // res[i - start] = NULL;
    int i = 0, j = 0;
    while (s[i++] != '\0')
        for (j = 0; substr[j] == s[i + j]; j++)
            if (substr[j + 1] == '\0')
                printf("%d", i + j + 1);
}

int main(void)
{
    char str[] = "I am a student.";
    char res[100];
    char sentences[] = "hello. my name is dave. goodbye.";
    char answer[] = "Hello. My name is dave. Goodbye.";

    afterString(str, "stu", res);

    // printf("afterString(%s,\"stu\"))\tdent.\t%s\n", str, res);

    return 0;
}