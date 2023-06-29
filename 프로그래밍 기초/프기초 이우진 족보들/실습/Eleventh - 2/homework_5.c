#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

int main(void)
{
    // 사용자로부터 입력 파일의 이름을 입력받는다.
    // char fileName[100] = {0};
    // scanf("%s", fileName);

    // char *ptr;
    // char *delimiter = " \n";

    // char buffer[SIZE] = {0};

    // FILE *fp = fopen(fileName, "r+");
    // while (feof(fp) == 0)
    // {
    //     fgets(buffer, SIZE, fp);

    //     // 공백을 기준으로 buffer를 짜름
    //     ptr = strtok(buffer, delimiter);
    //     // 처음의 이름을 판별하기 위해 count = 0으로 매 줄을 설정해 준다.
    //     int count = 0;
    //     // 전체 시험 점수를 더할 total
    //     int total = 0;
    //     while (ptr != NULL)
    //     {
    //         printf("%s\t", ptr);
    //         // 0이 아닌경우는 모두 숫자이다.
    //         if (count != 0)
    //         {
    //             total += atoi(ptr);
    //         }
    //         count++;
    //         ptr = strtok(NULL, delimiter);
    //     }
    //     printf("%.2lf\n", (double)total / (count - 1));
    //     memset(buffer, 0, SIZE);
    // }

    // fclose(fp);

    char fileName[100] = {0};
    scanf("%s", fileName);
    FILE *fp = fopen(fileName, "r");
    char name[100];
    while ((fscanf(fp, "%s", name) != EOF) && fp != NULL)
    {
        int score1, score2, score3;
        double total = 0;
        fscanf(fp, "%d %d %d", &score1, &score2, &score3);
        total = (double)(score1 + score2 + score3) / 3;
        printf("%s\t%d\t%d\t%d\t%.2lf\n", name, score1, score2, score3, total);
        memset(name, 0, 100);
    }
    fclose(fp);

    return 0;
}