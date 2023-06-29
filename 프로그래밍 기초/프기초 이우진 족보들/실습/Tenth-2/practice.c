#include <stdio.h>
#include <string.h>

struct complex
{
    double real;
    double img;
};

typedef struct complex complex;

complex paircomplex1(complex com);

void printcomplex(complex com);
void paircomplex2(complex *com);

int main(void)
{
    typedef struct Person_
    {
        char name[20];
        int age;
        char address[100];
    } Person, *ptrPerson;

    Person p1;
    strcpy(p1.name, "hyunseo");
    ptrPerson p_;
    p_ = &p1;
    printf("%s", p_->name);

    // // typedef struct Person Person_;
    // Person p1;
    // strcpy(p1.name, "hyunseo");
    // printf("p1.name >> %s\n", p1.name);

    // struct complex
    // {
    //     double real;
    //     double img;
    // } comp;

    // complex comp1 = {3, 4};

    // struct univ
    // {
    //     char title[50];   // name
    //     char address[50]; // address
    //     int students;     // 학생 수
    // };

    // struct univ ku = {"한국대학교", "서울시 서초구", 5000};
    // struct univ *ptr = &ku;

    // printf("학교: %s, 주소: %s, 학생수: %d\n", ptr->title, ptr->address, ptr->students);

    // complex comp = {3.4, 4.8};

    // complex pcomp;

    // printcomplex(comp);

    // pcomp = paircomplex1(comp);
    // printcomplex(pcomp);

    // paircomplex2(&pcomp);
    // printcomplex(pcomp);

    // enum color
    // {
    //     yellow,
    //     red,
    //     blue,
    //     magenta,
    //     green
    // } col;
    // col = green;
    // printf("%d\n", col);

    // enum day7
    // {
    //     sun,
    //     mon,
    //     tue,
    //     wed,
    //     thu,
    //     fri,
    //     sat
    // };
    // typedef enum day7 day;

    // day week;
    // week = sat;
    // switch (week)
    // {
    // case sun:
    //     printf("sunDay!");
    //     break;
    // case 1:
    //     printf("monDay!");
    //     break;
    // case 2:
    //     printf("tueDay!");
    //     break;
    // case 3:
    //     printf("wedDay!");
    //     break;
    // case 4:
    //     printf("tueDay!");
    //     break;
    // case 5:
    //     printf("friDay!");
    //     break;
    // case sat:
    //     printf("satDay!");
    //     break;

    // default:
    //     break;
    // }

    // enum TF
    // {
    //     true,
    //     false
    // };
    // typedef enum TF bool;
    // bool flag;

    // flag = true;

    return 0;
}

void printcomplex(complex com)
{
    printf("복소수 = %5.1f + %5.1fi\n", com.real, com.img);
}

complex paircomplex1(complex com)
{
    com.img = -com.img;
    return com;
}

void paircomplex2(complex *com)
{
    com->img = -com->img;
}