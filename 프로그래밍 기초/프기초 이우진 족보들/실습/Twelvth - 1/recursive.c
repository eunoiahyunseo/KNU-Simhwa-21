#include <stdio.h>

void printFTri(int idx, int n)
{

    if (idx == n + 1)
    {
        return;
    }

    for (int i = 0; i < idx; i++)
    {
        putchar('*');
    }
    putchar('\n');
    printFTri(idx + 1, n);

    for (int i = 0; i < idx - 1; i++)
    {
        putchar('*');
    }
    putchar('\n');
}

int main(void)
{

    printFTri(1, 5);
    return 0;
}