#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student_
{
    int std_id;
    char name[30];
    double score[3];
    double total;
} student;

int main(void)
{
    char inputName[100] = {0};
    char outputName[100] = {0};

    scanf("%s %s", inputName, outputName);
    FILE *fp_read, *fp_write;

    fp_read = fopen(inputName, "r");
    fp_write = fopen(outputName, "wb+");

    // 구조체 배열 초기화
    student list[7] = {0};

    int count = 0;

    while (fscanf(fp_read, "%d\t%s\t%lf\t%lf\t%lf", &list[count].std_id, list[count].name, &list[count].score[0], &list[count].score[1], &list[count].score[2]) != EOF)
    {
        list[count].total = list[count].score[0] + list[count].score[1] + list[count].score[2];
        fwrite(list + count, sizeof(student), 1, fp_write);
        printf("%d\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n", list[count].std_id, list[count].name, list[count].score[0], list[count].score[1], list[count].score[2], list[count].total);
        count++;
    }

    fclose(fp_read);
    fclose(fp_write);
}