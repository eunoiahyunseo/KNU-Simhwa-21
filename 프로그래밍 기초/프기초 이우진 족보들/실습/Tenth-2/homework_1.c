#include <stdio.h>
#include <string.h>

int main(void)
{

    typedef struct MovieData_
    {
        char title[50];
        char person[50];
        int year;
        int do_year;
    } MovieData;

    MovieData MD1;

    char title[50];
    gets(title);
    strcpy(MD1.title, title);

    char personName[50];
    gets(personName);
    strcpy(MD1.person, personName);

    int year;
    scanf("%d", &year);
    MD1.year = year;

    int do_year;
    scanf("%d", &do_year);
    MD1.do_year = do_year;

    printf("Title : %s\n", MD1.title);
    printf("Director : %s\n", MD1.person);
    printf("Year : %d\n", MD1.year);
    printf("RunningTime : %d\n", MD1.do_year);

    return 0;
}