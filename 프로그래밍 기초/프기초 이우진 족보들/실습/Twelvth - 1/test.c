#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct student_
{
    int age;
    char name[10];
} student, *ptrStudent;

int main(void)
{
    int i;
    int count = 0;
    ptrStudent ptrStudentList[MAX];

    ptrStudentList[count] = (ptrStudent)malloc(sizeof(student));
    ptrStudentList[count]->age = 20;
    strcpy(ptrStudentList[count]->name, "hyunseo");

    printf("student's age >> %d\nstudent's name >> %s\n", ptrStudentList[count]->age, ptrStudentList[count]->name);
}