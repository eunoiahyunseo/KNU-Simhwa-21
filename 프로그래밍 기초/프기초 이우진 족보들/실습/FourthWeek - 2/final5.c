
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int intArr[1000] = {0};

// 0이 입력될 때까지 정수를 입력받아 연결리스트를 만든 다음
// 해당 연결리스트에서 중간 값을 출력하고 중간 값을 제외한 값을 오름차순으로 출력하는 프로그램을 작성해보자
// 짝수개의 값인 경우 중간 값은 n/2 + 1번째로 한다.

// 입력에 중복되는 값은 주어지지 않는다.

typedef struct Node_
{
    int data;
    struct Node_ *next;
} Node, *pNode;

int printNode(pNode);
pNode insertNoDuplicate(pNode, int);
pNode deleteNode(pNode, int);
pNode appendNode(pNode, int);

int main(void)
{
    int value, count = 0, median;
    pNode head = NULL;

    while (1)
    {
        scanf("%d", &value);
        if (value == 0)
        {
            break;
        }

        head = appendNode(head, value);
        count++;
    }

    if (count % 2 == 0)
    {
        median = (count / 2) + 1;
    }
    else
    {
        median = (count / 2) + 1;
    }

    int deleteData;
    pNode deleteNode_ = head;
    for (int i = 0; i < median - 1; i++)
    {
        deleteNode_ = deleteNode_->next;
    }

    deleteData = deleteNode_->data;
    printf("median: %d\n", deleteData);

    pNode currentNode_ = head;
    pNode secondHead = NULL;
    for (int i = 0; i < count; i++)
    {
        secondHead = insertNoDuplicate(secondHead, currentNode_->data);
        currentNode_ = currentNode_->next;
    }
    // printNode(secondHead);

    secondHead = deleteNode(secondHead, deleteData);

    printNode(secondHead);
    return 0;
}

int printNode(pNode head)
{
    pNode currentNode = head;
    printf("list: ");
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