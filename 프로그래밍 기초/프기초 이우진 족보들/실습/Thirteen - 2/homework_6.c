

#include <stdio.h>
#include <stdlib.h>

typedef struct self_struct
{
    int data;
    struct self_struct *next;
} NODE;

NODE *insertList(NODE *head, int data);
NODE *appendList(NODE *head1, NODE *head2);
void traverseList(NODE *head);

void main()
{

    int input;
    NODE *head1 = NULL, *head2 = NULL;

    while (1)
    {

        scanf("%d", &input);

        if (input == 0)
            break;

        head1 = insertList(head1, input);
    }

    while (1)
    {

        scanf("%d", &input);

        if (input == 0)
            break;

        head2 = insertList(head2, input);
    }

    head1 = appendList(head1, head2);

    traverseList(head1);
}

NODE *insertList(NODE *head, int data)
{

    NODE *node, *curr;

    node = (NODE *)malloc(sizeof(NODE));

    node->data = data;
    node->next = NULL;

    if (head == NULL)
        head = node;

    else
    {
        curr = head;

        while (curr->next != NULL)
            curr = curr->next;

        curr->next = node;
    }

    return head;
}

NODE *appendList(NODE *head1, NODE *head2)
{

    NODE *curr;

    curr = head1;

    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = head2;

    return head1;
}

void traverseList(NODE *head)
{

    while (head != NULL)
    {
        printf("%d ", head->data);

        head = head->next;
    }
}