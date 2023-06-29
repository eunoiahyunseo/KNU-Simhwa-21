#include <stdio.h>
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
    FILE *fp_read;
    FILE *fp_write;
    student list[30] = {0};

    char input_fileName[100] = {0};
    char output_fileName[100] = {0};
    char editName[100] = {0};

    scanf("%s %s", input_fileName, output_fileName);
    scanf("%s", editName);

    if ((fp_read = fopen(input_fileName, "rb")) == NULL || (fp_write = fopen(output_fileName, "wb")) == NULL)
    {
        printf("Something happened\n");
    }

    int count = 0;
    int editIndex = 0;

    while (fread(list + count, sizeof(student), 1, fp_read) != 0)
    {
        if (!strcmp(editName, list[count].name))
        {
            editIndex = count;
            printf("%d\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n", list[count].std_id, list[count].name, list[count].score[0], list[count].score[1], list[count].score[2], list[count].total);
            scanf("%lf %lf %lf", &list[count].score[0], &list[count].score[1], &list[count].score[2]);
            list[count].total = list[count].score[0] + list[count].score[1] + list[count].score[2];
        }
        count++;
    }

    fwrite(list, sizeof(student), count, fp_write);

    fseek(fp_write, sizeof(student) * editIndex, SEEK_SET);

    fwrite(list + editIndex, sizeof(student), 1, fp_write);

    for (int i = 0; i < count; i++)
    {
        printf("%d\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n", list[i].std_id, list[i].name, list[i].score[0], list[i].score[1], list[i].score[2], list[i].total);
    }

    fclose(fp_read);
    fclose(fp_write);

    return 0;
}