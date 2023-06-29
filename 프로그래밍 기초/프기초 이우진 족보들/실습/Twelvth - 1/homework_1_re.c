#include <stdio.h>

typedef struct student
{
    int std_id;
    char name[30];
    double score[3];
    double total;
} student;

int main(void)
{
    student list[7] = {0, 0, 0, 0, 0, 0, 0, 0};
    char fname[30];
    char fout[30];
    int i = 0;

    FILE *f;
    FILE *fp;

    gets(fname);
    gets(fout);

    f = fopen(fname, "r");
    fp = fopen(fout, "wb");

    while (fscanf(f, "%d\t%s\t%lf\t%lf\t%lf", &list[i].std_id, list[i].name, &list[i].score[0], &list[i].score[1], &list[i].score[2]) != EOF)
    {

        list[i].total = list[i].score[0] + list[i].score[1] + list[i].score[2];
        fwrite(&list[i], sizeof(student), 1, fp);
        printf("%d\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n", list[i].std_id, list[i].name, list[i].score[0], list[i].score[1], list[i].score[2], list[i].total);

        i++;
    }

    fclose(f);
    fclose(fp);
}