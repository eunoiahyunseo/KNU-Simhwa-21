#include <stdio.h>
#include <string.h>

typedef struct student
{
    char name[100];
    int sc1;
    int sc2;
    int sc3;
    double avg;
} student;

int main()
{
    FILE *fp;
    student get[100];
    char get2[100];
    int stop = 0;
    int count = 0;
    int check;
    gets(get2);
    fp = fopen(get2, "r");
    while (1)
    {
        if (stop == 0)
        {
            check = fscanf(fp, "%s %d %d %d", get[count].name, &get[count].sc1, &get[count].sc2, &get[count].sc3);
            printf("check >> %d\n", check);
            get[count].avg = (double)(get[count].sc1, get[count].sc2, get[count].sc3) / 3;
            printf("get[%d] >> %s %d %d %d %.2lf\n", count, get[count].name, get[count].sc1, get[count].sc2, get[count].sc3, get[count].avg);
            count++;

            if (feof(fp))
            {
                stop = 1;
            }
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < count; i++)
    {
        printf("%s\t%d\t%d\t%d\t%.2lf\n", get[count].name, get[count].sc1, get[count].sc2, get[count].sc3, get[count].avg);
    }
    fclose(fp);
}