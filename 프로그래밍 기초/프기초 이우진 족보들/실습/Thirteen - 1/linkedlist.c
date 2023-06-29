#include <stdio.h>
#include <stdlib.h>

typedef struct Data_
{
    int n;
    // 자기 참조 구조체는 반드시 구조체의 멤버 변수 중의 하나가 자신의 구조체 포인터 변수이어야 함
    struct Data_ *next;

    // 자기 참조 구조체는 동일 구조체의 표현을 여러 개 만들어 연결할 수 있는 기능이 가능
} Data, *pData;

void printData(pData h)
{
    pData p = h;

    while (p != NULL)
    {
        printf("%d ", p->n);
        p = p->next;
    }
    printf("\n");
}

int main(void)
{
    pData first = NULL, second = NULL;
    first = (pData)malloc(sizeof(Data));
    second = (pData)malloc(sizeof(Data));

    first->n = 100;
    first->next = second;
    second->n = 200;
    second->next = NULL;

    printData(first);

    return 0;
}