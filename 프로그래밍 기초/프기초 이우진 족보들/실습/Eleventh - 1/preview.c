#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
    char name[20];
    int age;
    char address[100];
};

int main(void)
{
    typedef struct Person Person;
    Person *p1 = malloc(sizeof(Person));
    p1->age = 10;
    printf("p1 age >> %d", p1->age);

    return 0;
}