#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node_
{
    int data;
    struct Node_ *next;
} Node, *pNode;

int printNode(pNode);
pNode appendNode(pNode, int);
pNode insertSorted(pNode, int);
pNode deleteNode(pNode, int);

int main(void)
{
    int i;
    pNode head = NULL;
    head = appendNode(head, 30);
    head = appendNode(head, 50);
    head = appendNode(head, 70);

    printNode(head);

    printf("\n-------------------------------\n");

    head = insertSorted(head, 20);
    head = insertSorted(head, 60);
    head = insertSorted(head, 80);

    printNode(head);

    printf("\n-------------------------------\n");

    head = deleteNode(head, 60);
    head = deleteNode(head, 20);
    head = deleteNode(head, 80);

    printNode(head);

    return 0;
}
int printNode(pNode head)
{
    pNode currentNode = head;
    if (currentNode == NULL)
    {
        return 0;
    }
    else
    {
        while (currentNode != NULL)
        {
            printf("%d ", currentNode->data);
            currentNode = currentNode->next;
        }
        return 1;
    }
}

pNode appendNode(pNode head, int inputData)
{
    pNode appendData = malloc(sizeof(Node));
    appendData->data = inputData;
    appendData->next = NULL;

    if (head == NULL)
    {
        head = appendData;
    }
    else
    {
        pNode currentNode = head;
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = appendData;
    }

    return head;
}

pNode insertSorted(pNode head, int insertData)
{
    pNode insertNode = malloc(sizeof(Node));
    insertNode->data = insertData;

    pNode beforeCurrentNode = head;
    pNode currentNode = head;

    while (currentNode != NULL)
    {
        if (currentNode->data > insertData)
        {
            break;
        }
        beforeCurrentNode = currentNode;
        currentNode = currentNode->next;
    }

    if (currentNode == head)
    {
        insertNode->next = head;
        head = insertNode;
    }
    else
    {
        insertNode->next = currentNode;
        beforeCurrentNode->next = insertNode;
    }
    return head;
}

pNode deleteNode(pNode head, int inputData)
{
    pNode beforeCurrentNode = head;
    pNode currentNode = head;

    while (currentNode != NULL)
    {
        if (currentNode->data == inputData)
        {
            break;
        }

        if (currentNode->data > inputData)
        {
            // cannot found delete data
            return head;
        }

        beforeCurrentNode = currentNode;
        currentNode = currentNode->next;
    }

    if (currentNode == NULL)
    {
        return head;
    }
    else if (currentNode == head)
    {
        head = head->next;
        free(currentNode);
        return head;
    }
    else
    {
        beforeCurrentNode->next = currentNode->next;
        free(currentNode);
        return head;
    }
}