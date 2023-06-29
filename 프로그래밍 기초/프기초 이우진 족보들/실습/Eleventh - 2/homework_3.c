#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // 학생들의 성적이 정수형으로 저장된 텍스트 파일을 읽어서 90점 이상의 개수와 해당
    // 점수들을 화면에 출력하는 프로그램을 작성하시오
    char fileName[100] = {0};
    int size, number, count;

    // 파일 이름을 입력 받는다.
    scanf("%s", fileName);

    FILE *fp = fopen(fileName, "r+");

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    rewind(fp);

    char resultBuffer[size + 1];
    memset(resultBuffer, 0, size);

    int buffer[5] = {0};

    while (feof(fp) == 0)
    {
        // \n까지의 문자열을 buffer에 집어 넣은 후 fp을 읽은 만큼 이동시킨다.
        fgets(buffer, sizeof(buffer), fp);
        const number = atoi(buffer);
        if (number >= 90)
        {
            resultBuffer[count] = number;
            count++;
        }
    }

    // 90점 이상의 개수를 출력한다.
    printf("%d\n", count);
    for (int i = 0; i < count; i++)
    {
        printf("%d\n", resultBuffer[i]);
    }

    fclose(fp);

    return 0;
}