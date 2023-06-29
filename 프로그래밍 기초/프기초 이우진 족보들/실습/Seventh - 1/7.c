#include <stdio.h>
#include <string.h>

int main(void)
{
    char *strarr[] = {"c", "C++", "java", "c#"};
    // 포인터 배열로 생각 할 수 있다.

    printf("%lu\n", sizeof(strarr) / sizeof(char *));
    printf("%lu\n", strlen(strarr[1]));
    for (int i = 0; i < sizeof(strarr) / sizeof(char *); i++)
    {
        for (int j = 0; j < strlen(strarr[i]); j++)
        {
            // printf("%d\n", j);
            printf("%c", *(*(strarr + i) + j));
        }
        printf("\n");
    }
    printf("%s\n", strarr[1]);
    printf("%c\n", *(*(strarr + 1) + 1));
}