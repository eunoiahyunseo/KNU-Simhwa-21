#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include <stdio.h>

#define type(x) _Generic((x),                                      \
                         _Bool                                     \
                         : "_Bool", unsigned char                  \
                         : "unsigned char",                        \
                           char                                    \
                         : "char", signed char                     \
                         : "signed char",                          \
                           short int                               \
                         : "short int", unsigned short int         \
                         : "unsigned short int",                   \
                           int                                     \
                         : "int", unsigned int                     \
                         : "unsigned int",                         \
                           long int                                \
                         : "long int", unsigned long int           \
                         : "unsigned long int",                    \
                           long long int                           \
                         : "long long int", unsigned long long int \
                         : "unsigned long long int",               \
                           float                                   \
                         : "float", double                         \
                         : "double",                               \
                           long double                             \
                         : "long double", char *                   \
                         : "char *",                               \
                           void *                                  \
                         : "void *", int *                         \
                         : "int *",                                \
                           default                                 \
                         : "unknown")

#define SIZE 2

int main(void)
{
    // file1의 내용을 읽고 파일에 나오는 모든 숫자 문자를 file2에 쓰고
    // 숫자의 합을 화면에 출력하는 프로그램을 작성하시오

    char fileName_1[100] = {0};
    char fileName_2[100] = {0};

    // 숫자를 만날 때 마다 1씩 증가
    int count = 0;
    // 수를 전체 더한 값을 저장하는 변수
    int total = 0;

    scanf("%s %s", fileName_1, fileName_2);

    FILE *fp = fopen(fileName_1, "r+");

    char resultBuffer[100] = {0};

    char buffer[SIZE];
    memset(buffer, 0, SIZE);

    while (feof(fp) == 0)
    {
        // 1바이트씩 file1의 내용을 읽어간다.
        fread(buffer, SIZE - 1, 1, fp);

        // 아스키 문자가 10진수로 바꿔질 수 있다면
        if (isdigit(buffer[0]))
        {
            resultBuffer[count] = buffer[0];
            count++;
        }
        memset(buffer, 0, SIZE);
    }

    FILE *fp_ = fopen(fileName_2, "w+");

    fwrite(resultBuffer, count, 1, fp_);

    for (int i = 0; i < count; i++)
    {
        // printf("resultBuffer[%d] >> %c type >> %s\n", i, resultBuffer[i], type(resultBuffer[i]));
        total += resultBuffer[i] - '0';
    }

    printf("%d\n", total);
    fclose(fp);

    return 0;
}