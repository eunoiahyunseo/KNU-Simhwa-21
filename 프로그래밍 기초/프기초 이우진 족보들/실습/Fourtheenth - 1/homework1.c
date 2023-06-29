#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int intArr[1000] = {0};
typedef struct Node_
{
    int data;
    struct Node_ *next;
} Node, *pNode;

int printNode(pNode);
pNode appendNode(pNode, int);
pNode insertNoDuplicate(pNode, int);
pNode deleteNode(pNode, int);
pNode removeList(pNode, pNode);

int main(void)
{
    int i, value, data;
    pNode head = NULL;
    pNode delete = NULL;
    while (1)
    {
        scanf("%d", &value);
        if (value == 0)
        {
            break;
        }

        head = insertNoDuplicate(head, value);
    }

    memset(intArr, 0, sizeof(int) * 1000);

    while (1)
    {
        scanf("%d", &value);
        if (value == 0)
        {
            break;
        }

        delete = insertNoDuplicate(delete, value);
    }

    head = removeList(head, delete);
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

pNode insertNoDuplicate(pNode head, int insertData)
{
    int count = 0;

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
        if (intArr[insertData] == 0)
        {
            // printf("doing_1");
            intArr[insertData] = 1;
            insertNode->next = head;
            head = insertNode;
        }
        else
        {
            // printf("doing_2");
            intArr[insertData] += 1;
        }
    }
    else
    {
        if (intArr[insertData] == 0)
        {
            intArr[insertData] = 1;
            insertNode->next = currentNode;
            beforeCurrentNode->next = insertNode;
        }
        else
        {
            intArr[insertData] += 1;
        }
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

pNode removeList(pNode src_head, pNode del_head)
{
    pNode src = src_head;
    pNode del = del_head;
    // printf("doing_1\n");

    while (del != NULL)
    {
        // printf("doing_2\n");
        src = deleteNode(src, del->data);
        del = del->next;
    }

    return src;
}