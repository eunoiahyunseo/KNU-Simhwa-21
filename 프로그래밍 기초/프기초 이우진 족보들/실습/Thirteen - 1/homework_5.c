#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list
{
    double data;
    struct linked_list *next;
} NODE, *PNODE;

void printMinMax(PNODE h);
PNODE insertHead(PNODE h, double data);

int main(void)
{
    int i, n;
    double data;
    PNODE header = NULL;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%lf", &data);
        header = insertHead(header, data);
    }
    // printf("adsf");
    printMinMax(header);
    return 0;
}

PNODE insertHead(PNODE h, double data)
{
    PNODE node;
    node = (PNODE)malloc(sizeof(NODE));

    node->data = data;
    node->next = h;

    h = node;

    return h;
}

void printMinMax(PNODE h)
{
    PNODE header = h;

    double min = header->data;
    double max = header->data;

    header = header->next;

    while (header != NULL)
    {
        if (header->data < min)
        {
            min = header->data;
        }

        if (header->data > max)
        {
            max = header->data;
        }
        header = header->next;
    }
    printf("min:%.1lf\n", min);
    printf("max:%.1lf", max);
}