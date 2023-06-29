#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list
{
    int data;
    struct linked_list *next;
} NODE, *pNode;

pNode insertHead(pNode h, int data);
pNode append(pNode h, int input);
void increaseList(pNode h);
void printList(pNode h);

int main(void)
{
    pNode h = NULL;
    int value;

    while (1)
    {
        scanf("%d", &value);

        if (value == 0)
        {
            break;
        }
        else
        {
            h = append(h, value);
        }
    }

    pNode header = h;

    while (header != NULL)
    {
        header = header->next;
    }

    increaseList(h);
    printList(h);

    return 0;
}

// pNode insertHead(pNode h, int data)
// {
//     pNode node;
//     node = (pNode)malloc(sizeof(NODE));

//     node->data = data;
//     node->next = h;

//     h = node;
//     return h;
// }

pNode append(pNode h, int input)
{
    pNode p, curr;
    curr = (pNode)malloc(sizeof(NODE));
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

void increaseList(pNode h)
{
    pNode p;
    p = h;
    while (p != NULL)
    {
        p->data = p->data + 10;
        p = p->next;
    }
}

void printList(pNode h)
{
    pNode p;
    p = h;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
