#include <stdio.h>
#include <stdlib.h>
typedef struct Student_
{
    char name[20];
    int age;
} Student, *ptrStudent;
// 연관된 멤버로 구성되는 통합 자료형으로 대표적인 유도자료형

struct complex
{
    double real;
    double img;
};

typedef struct complex complex;

typedef struct Food_
{
    char name[20];
    int star;
} Food;

void printFood(const Food *food)
{
    printf("food's name >> %s\nfood's star >> %d\n", food->name, food->star);
}

int main(void)
{
    // typedef struct Student Student;
    // Student stu1;

    // Student stu1 = {"Hyunseo Lee", 20};
    // printf("name >> %s\n", stu1.name);

    // struct complex
    // {
    //     double real;
    //     double img;
    // } comp;

    // complex comp1 = {3, 4}, comp2 = {2, 5};
    // comp.real = comp1.real;
    // comp.img = comp2.img;

    // comp = comp2;
    // 다른 자료형 이르몰 오류가 난다.

    // struct univ
    // {
    //     char title[50];
    //     char address[50];
    //     int students;
    // };

    // struct univ ku = {"한국대학교", "서울시 서초구", 5000};
    // struct univ *ptr = &ku;

    /*
        *ptr.title; // 는 연산자 우선순위에 따라 *(ptr.title);과 같으므로 오류가 난다.
        (*ptr).title; // 와 같이 해야 한다.
        또한 이는 ptr->title과 같다
    */

    // typedef enum bool_
    // {
    //     false,
    //     true
    // } bool;

    // bool isChekced = true;
    // printf("%d\n", isChekced);

    // bool isChekced_ = false;
    // printf("%d\n", isChekced_);

    // enum pl
    // {
    //     c = 1972,
    //     cpp = 1983,
    //     java = 1995,
    //     cs = 2000
    // };
    // typedef enum pl pl;

    // pl testInt = c;
    // printf("%d\n", testInt);

    // typedef enum Day7_
    // {
    //     sun,
    //     mon,
    //     tue,
    //     wed,
    //     thu,
    //     fri,
    //     sat
    // } Day;

    // Day week;

    // switch (week)
    // {
    // case sun:
    //     break;
    // default:
    //     break;
    // }

    // Food *foodArray[4];

    // Food chicken = {"chicken", 10};
    // foodArray[0] = &chicken;

    // printFood(foodArray[0]);

    char *charArr[3] = {0};
    charArr[0] = "asdf";
    printf("%s\n", charArr[0]);

    return 0;
}