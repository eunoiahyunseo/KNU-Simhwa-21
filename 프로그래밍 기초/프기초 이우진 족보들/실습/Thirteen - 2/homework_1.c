#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list
{
    int data;
    struct linked_list *next;
} NODE, *pNode;

pNode insertHead(pNode h, int data);
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
            h = insertHead(h, value);
        }
    }

    int searchValue;
    int found = -1;
    scanf("%d", &searchValue);

    pNode header = h;

    while ((header != NULL))
    {
        if (header->data == searchValue)
        {
            printf("true");
            found = 1;
            break;
        }
        header = header->next;
    }

    if (found < 0)
    {
        printf("false");
    }

    return 0;
}

pNode insertHead(pNode h, int data)
{
    pNode node;
    node = (pNode)malloc(sizeof(NODE));

    node->data = data;
    node->next = h;

    h = node;
    return h;
}