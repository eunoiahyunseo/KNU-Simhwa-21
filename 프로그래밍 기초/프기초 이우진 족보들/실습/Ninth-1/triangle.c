#include <stdio.h>

void printTri(int idx, int n);
void printRTri(int idx, int n);

int main(void)
{

    printTri(1, 5);
    return 0;
}

void printTri(int idx, int n)
{
    int i;

    if (idx == n)
    {
        return;
    }

    for (int i = 0; i < idx; i++)
    {
        printf("*");
    }

    printf("\n");

    printTri(idx + 1, n);

    for (int i = 0; i < idx; i++)
    {
        printf("*");
    }
    printf("\n");
}

// void printRTri(int idx, int n)
// {
// }