#include <stdio.h>
#include <stdlib.h>

typedef struct _Data
{
    int data;
    struct _Data *next;
} Data, *pData;

pData append(pData h, int input);
void printData(pData h);

int main(void)
{

    int i, num;
    pData h = NULL;

    for (i = 0; i < 5; i++)
    {
        scanf("%d", &num);
        h = append(h, num);
    }
    printData(h);

    return 0;
}

void printData(pData h)
{
    pData p;
    p = h;
    if (h == NULL)
    {
        return;
    }
    printf("출력 시작 -------------------\n");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

pData append(pData h, int input)
{
    pData p, curr;
    curr = (pData)malloc(sizeof(Data));
    curr->next = NULL;
    curr->data = input;

    if (h == NULL)
    {
        h = curr;
    }
    else
    {
        p = h;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = curr;
    }
    return h;
}