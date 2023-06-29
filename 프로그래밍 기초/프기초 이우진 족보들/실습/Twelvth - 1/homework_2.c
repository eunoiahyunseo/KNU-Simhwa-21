#include <stdio.h>
#include <string.h>

typedef struct student
{
    int std_id;
    char name[30];
    double score[3];
    double total;
} student;

int main(void)
{
    student list[100] = {0, 0, 0, 0};
    char fname[30];
    char fout[30];
    int i = 0, j = 0;
    char some[30];

    FILE *f;
    FILE *fp;

    scanf("%s", fname);
    scanf("%s", fout);
    f = fopen(fname, "rb");
    fp = fopen(fout, "wb");

    scanf("%s", some);

    while (fread(&list[i], sizeof(student), 1, f) != 0)
    {
        if ((strcmp(some, list[i].name)) == 0)
        {
            printf("%d\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n", list[i].std_id, list[i].name, list[i].score[0], list[i].score[1], list[i].score[2], list[i].total);
            scanf("%lf %lf %lf", &list[i].score[0], &list[i].score[1], &list[i].score[2]);
            list[i].total = list[i].score[0] + list[i].score[1] + list[i].score[2];
        }

        i++;
    }
    fwrite(list, sizeof(student), i, fp);

    f = fopen(fout, "rb");

    fread(list, sizeof(student), i, f);

    for (j = 0; j < i; j++)
    {
        printf("%d\t%s\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n", list[j].std_id, list[j].name, list[j].score[0], list[j].score[1], list[j].score[2], list[j].total);
    }

    fclose(f);
    fclose(fp);
}