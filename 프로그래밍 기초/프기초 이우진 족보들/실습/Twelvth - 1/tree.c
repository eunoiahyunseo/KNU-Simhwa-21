#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000
#define BASE 0

typedef struct TreeNode
{
    struct TreeNode *left;
    char data;
    struct TreeNode *right;

} TreeNode, *ptrTreeNode;

ptrTreeNode TreeNodeList[MAX];

// 추가한 노드의 개수를 나타내는 count변 여보세요
static int count = 0;

void mallocNode(ptrTreeNode *findNode, char *direction, char insertData)
{
    TreeNodeList[count] = (ptrTreeNode)malloc(sizeof(TreeNode));
    TreeNodeList[count]->data = insertData;
    TreeNodeList[count]->left = NULL;
    TreeNodeList[count]->right = NULL;

    if (!strcmp(direction, "right"))
    {
        (*findNode)->right = TreeNodeList[count];
    }
    else
    {
        (*findNode)->left = TreeNodeList[count];
    }
    count++;
}

// 트리 추가하는 메서드
void insertNode(ptrTreeNode *headNodePtr, char insertData)
{
    // CASE1: 헤드 노드에 메모리가 할당되어있지 않다면
    if (*headNodePtr == NULL)
    {
        TreeNodeList[count] = (ptrTreeNode)malloc(sizeof(TreeNode));
        TreeNodeList[count]->left = NULL;
        TreeNodeList[count]->right = NULL;
        TreeNodeList[count]->data = insertData;
        *headNodePtr = TreeNodeList[count];
        count++;
    }
    else
    {
        // CASE2: 헤드가 있다면
        // ptrTreeNode findNode = TreeNodeList[BASE];
        ptrTreeNode findNode = *headNodePtr;

        while (1)
        {
            // 만약 추가 하려는 데이터가 원래의 데이터보다 작다면 -> 왼쪽으로!
            if (insertData < findNode->data)
            {
                // 만약 왼쪽노드가 NULL이 아니라면 추가하면 그 다음 노드로 옮겨 가면 되겠지
                if (findNode->left != NULL)
                {
                    findNode = findNode->left;
                }
                // 만약 왼쪽 노드가 비었다면 추가해야 한다.
                else
                {
                    mallocNode(&findNode, "left", insertData);
                    break;
                }
            }
            else
            {
                // 만약 추가 하려는 데이터가 원래의 데이터보다 크다면 -> 오른쪽으로!
                if (findNode->right != NULL)
                {
                    findNode = findNode->right;
                }
                else
                {
                    mallocNode(&findNode, "right", insertData);
                    break;
                }
            }
        }
    }
}

// 전위 순회
void preorder(TreeNode *traversalNode)
{
    // 만약 NULL이라면 끝낸다.
    if (traversalNode != NULL)
    {
        printf("[%c]", traversalNode->data);
        preorder(traversalNode->left);
        preorder(traversalNode->right);
    }
}

// 중순위 순회
void inorder(TreeNode *traversalNode)
{
    if (traversalNode != NULL)
    {
        inorder(traversalNode->left);
        printf("[%c]", traversalNode->data);
        inorder(traversalNode->right);
    }
}

void postorder(TreeNode *traversalNode)
{
    if (traversalNode != NULL)
    {
        postorder(traversalNode->left);
        postorder(traversalNode->right);
        printf("[%c]", traversalNode->data);
    }
}

int main(void)
{
    TreeNode *headNode = NULL;

    insertNode(&headNode, 'D');
    insertNode(&headNode, 'A');
    insertNode(&headNode, 'F');
    insertNode(&headNode, 'B');
    insertNode(&headNode, 'C');
    insertNode(&headNode, 'E');
    insertNode(&headNode, 'G');

    printf("start preorder traversal ---------------\n");
    preorder(headNode);
    printf("\n");

    printf("start inorder traversal ----------------\n");
    inorder(headNode);

    printf("\n");

    printf("start postorder traversal ----------------\n");
    postorder(headNode);

    printf("\n");

    for (int i = count - 1; i > 0; i--)
    {
        free(TreeNodeList[i]);
    }
}