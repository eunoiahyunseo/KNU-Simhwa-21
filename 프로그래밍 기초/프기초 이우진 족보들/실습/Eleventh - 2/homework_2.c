#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{

    // 텍스트 파일 이름을 입력받아 해당 파일의 내용을 읽어서 모두 대문자로 바꾸어서
    // 파일과 표준출력으로 출력하는 프로그램을 작성하시오

    char fileName_1[100] = {0};
    char fileName_2[100] = {0};
    // 파일 사이즈
    int size;

    scanf("%s %s", fileName_1, fileName_2);

    FILE *fp = fopen(fileName_1, "r+");

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);

    // 파일 포인터를 다시 처음으로 rewind 시킨다.
    rewind(fp);

    char buffer[size + 1];
    memset(buffer, 0, size + 1);

    // buffer에 data.txt의 내용을 저장한다.
    fread(buffer, size, 1, fp);
    // printf("buffer >> %s\n", buffer);
    // buffer에 있는 문자열을 대문자로 싹다 변경

    for (int i = 0; i < strlen(buffer); i++)
    {
        // 만약 소문자면
        if (islower(buffer[i]) != 0)
        {
            buffer[i] -= ('a' - 'A');
        }
    }

    // printf("대문자 변환 buffer >> %s\n", buffer);

    FILE *fp_ = fopen(fileName_2, "w+");

    // 여기서 size + 1을 하게되면 명시적으로 buffer에 들어간 NULL이 나오게 된다
    // 즉 버퍼에 문자열을 저장할 때와 다르게 size + 1이 아닌 size만큼을 저장한다.
    printf("%s", buffer);
    fwrite(buffer, size, 1, fp_);

    fclose(fp);

    return 0;
}