#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 반복 x check
int count = 0;

int main(void)
{

    char fileName[30];
    scanf("%s", fileName);

    int size = 0;

    FILE *fp = fopen(fileName, "r+");

    while (!ferror(fp) && !feof(fp) && count == 0)
    {
        // 문서의 길이를 size에 저장한다.
        fseek(fp, 0, SEEK_END);
        size = ftell(fp);
        // 파일 포인터 맨 앞으로 돌려보냄
        rewind(fp);
        // NULL이 들어갈 자리까지 메모리 지정해준다.
        char buffer[size + 1];
        memset(buffer, 0, size + 1);
        fread(buffer, sizeof(buffer) - 1, 1, fp);
        printf("%s", buffer);
        count++;
    }

    fclose(fp);

    return 0;
}