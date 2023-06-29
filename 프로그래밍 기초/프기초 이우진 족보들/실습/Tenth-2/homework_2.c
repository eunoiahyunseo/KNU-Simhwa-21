#include <stdio.h>
#include <string.h>
#define SIZE 100

typedef struct employee_
{
    int number;         // 사번
    char name[SIZE];    // 이름
    char address[SIZE]; // 주소
    int salary;         // 월급
    double incentive;   // 인센티브
    double anual;       // 연봉
} employee;

int main(void)
{
    employee member[3] = {0};

    for (int i = 0; i < 3; i++)
    {
        scanf("%d\n", &member[i].number);
        gets(member[i].name);
        gets(member[i].address);
        scanf("%d\n", &member[i].salary);
        scanf("%lf\n", &member[i].incentive);
        member[i].anual = member[i].salary * (12 + member[i].incentive);
    }

    for (int i = 0; i < 3; i++)
    {
        printf("%d\t%s\t%s\t%d\t%.0lf%%\t%.1lf\n", member[i].number, member[i].name, member[i].address, member[i].salary, member[i].incentive * 100, member[i].anual);
    }

    return 0;
}