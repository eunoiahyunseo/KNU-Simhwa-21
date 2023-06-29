#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct student_
{
    char name[20];
    double midterm;
    double final;
    double quiz;
} student, *pStudent;

typedef struct score
{
    int no;
    char name[20];
    double midterm;
    double final;
    double quiz;
    double total;
} score, *pScore;

int main(void)
{
    FILE *fp_read;
    FILE *fp_write;
    int value, i;

    pStudent studentList;
    studentList = (pStudent)malloc(sizeof(student) * MAX);

    pScore scoreList;
    scoreList = (pScore)malloc(sizeof(score) * MAX);

    char inputFileName[100], outputFileName[100];
    scanf("%s %s", inputFileName, outputFileName);

    fp_read = fopen(inputFileName, "rb");
    fp_write = fopen(outputFileName, "w");
    fread(&value, sizeof(int), 1, fp_read);

    for (i = 0; i < value; i++)
    {
        fread(&studentList[i], sizeof(student), 1, fp_read);

        scoreList[i].no = i + 1;
        strcpy(scoreList[i].name, studentList[i].name);
        scoreList[i].midterm = studentList[i].midterm;
        scoreList[i].final = studentList[i].final;
        scoreList[i].quiz = studentList[i].quiz;

        scoreList[i].total = scoreList[i].midterm + scoreList[i].final + scoreList[i].quiz;

        fprintf(fp_write, "%d %s %.1lf %.1lf %.1lf %.1lf\n", scoreList[i].no, scoreList[i].name, scoreList[i].midterm, scoreList[i].final, scoreList[i].quiz, scoreList[i].total);
    }

    fclose(fp_read);
    fclose(fp_write);
    free(studentList);
    free(scoreList);

    return 0;
}