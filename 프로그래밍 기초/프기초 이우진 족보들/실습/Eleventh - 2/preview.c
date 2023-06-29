#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

    /*
        char *s1 = "Hello world!";
        FILE *fp = fopen("test.txt", "w");
        fputs("Hello world!", fp);
        fwrite(s1, strlen(s1), 1, stdout);
    */

    /*
        char buffer[20];
        FILE *fp = fopen("test.txt", "r");
        // fgets함수는 \n에 따라 읽은 결과가 달라지므로 사요엥 주의해야 한다.
        fgets(buffer, sizeof(buffer), fp);
        // printf("%d", strlen(buffer));
        fputs(buffer, stdout);
    */

    // 원래 미리 파일 크기를 구해와야 하지만 여기서는 fgets, fread 함수의 사용 방법을 보여주기 위해서
    // 간단하게 13바이트보다 큰 20바이트로 설정했다
    // char buffer[20] = {0};
    // FILE *fp = fopen("test.txt", "r");
    // // fread함수는 fgets함수와는 달리 \n가 있든 없든 무조건 지정된 크기만큼 읽습니다.
    // fread(buffer, sizeof(buffer), 1, fp);
    // printf("%s\n", buffer);
    // fclose(fp);

    // 파일 크기 구하기
    // int size;
    // FILE *fp = fopen("test.txt", "r");

    // // fseek(fp, 0, SEEK_SET) // 파일 포인터를 파일의 처음으로 이동시킴
    // // fseek(fp, -10, SEEK_CUR) // 파일 포인터를 현재 위치에서 10바이트만큼 역방향으로 이동
    // // fseek(fp, 0, SEEK_END) // 파일 포인터를 파일의 끝으로 이동시킴

    // fseek(fp, 0, SEEK_END);
    // size = ftell(fp);
    // printf("%d\n", size);
    // fclose(fp);

    // char *buffer;
    // int size;
    // int count;

    // FILE *fp = fopen("test.txt", "r");

    // fseek(fp, 0, SEEK_END);
    // size = ftell(fp);

    // buffer = (char *)malloc(size + 1); // 문자열 마지막 NULL을 위해 + 1을 해준다.
    // memset(buffer, 0, size + 1);

    // fseek(fp, 0, SEEK_SET);
    // count = fread(buffer, size, 1, fp);

    // printf("%s size: %d, count: %d\n", buffer, size, count);

    // fclose(fp);
    // free(buffer);

    // char buffer[10] = {0};
    // FILE *fp = fopen("test.txt", "r");

    // fseek(fp, 2, SEEK_SET);  // 파일 포인터를 파일 처음위치에서 2바이트만큼 순방향으로 이동
    // fread(buffer, 3, 1, fp); // 3바이트만큼 읽음. 3바이트만큼 순방향으로 읻공

    // printf("%s\n", buffer);

    // memset(buffer, 0, 10);

    // fseek(fp, 3, SEEK_CUR);
    // fread(buffer, 4, 1, fp);

    // printf("%s\n", buffer);
    // fclose(fp);

    // char *s1 = "abcd";
    // char buffer[20] = {0};

    // FILE *fp = fopen("test.txt", "r+"); // test.txt파일을 읽기/쓰기 모드로

    // fseek(fp, 3, SEEK_SET);
    // fwrite(s1, strlen(s1), 1, fp);

    // rewind(fp);
    // fread(buffer, sizeof(buffer) - 1, 1, fp);

    // printf("%s\n", buffer);
    // fclose(fp);

    // char buffer[5] = {0};
    // int count = 0;
    // int total = 0;

    // FILE *fp = fopen("test.txt", "r");

    // while (feof(fp) == 0)
    // {
    //     count = fread(buffer, sizeof(char), 4, fp);
    //     printf("doing\n");
    //     printf("%s", buffer);
    //     memset(buffer, 0, 5);
    //     total += count;
    // }

    // printf("\ntotal: %d\n", total);
    // fclose(fp);

#pragma pack(push, 1)
    struct Data
    {
        short num1;
        short num2;
        short num3;
        short num4;
    };
#pragma pack(pop)

    // struct Data d1;
    // d1.num1 = 100;
    // d1.num2 = 200;
    // d1.num3 = 300;
    // d1.num4 = 400;

    // FILE *fp = fopen("data.bin", "wb");
    // fwrite(&d1, sizeof(d1), 1, fp);

    struct Data d2;
    FILE *fp = fopen("data.bin", "rb");
    fread(&d2, sizeof(d2), 1, fp);

    printf("%d %d %d %d\n", d2.num1, d2.num2, d2.num3, d2.num4);
    fclose(fp);

    return 0;
}