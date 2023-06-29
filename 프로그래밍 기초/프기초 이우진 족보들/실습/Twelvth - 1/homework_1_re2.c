#include <stdio.h>

typedef struct student_
{
    int std_id;
    char name[30];
    double score[3];
    double total;
} student;

int main(void)
{
    FILE *fp_read;
    FILE *fp_write;
    student list[30] = {0};

    char input_fileName[100] = {0};
    char output_fileName[100] = {0};

    gets(input_fileName);
    gets(output_fileName);

    if ((fp_read = fopen(input_fileName, "r")) == NULL || (fp_write = fopen(output_fileName, "wb")) == NULL)
    {
        printf("Something happened\n");
    }

    int count = 0;

    while (fscanf(fp_read, "%d\t%s\t%lf\t%lf\t%lf", &list[count].std_id, list[count].name, &list[count].score[0], &list[count].score[1], &list[count].score[2]) != EOF)
    {
        list[count].total = list[count].score[0] + list[count].score[1] + list[count].score[2];
        printf("%d\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n", list[count].std_id, list[count].name, list[count].score[0], list[count].score[1], list[count].score[2], list[count].total);
        count++;
    }

    fwrite(list, sizeof(student), count, fp_write);

    fclose(fp_read);
    fclose(fp_write);

    return 0;
}