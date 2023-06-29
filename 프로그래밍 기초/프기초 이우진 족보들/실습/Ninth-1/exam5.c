#include <stdio.h>

void printLess(int n)
{
    if (n <= 0)
    {
        return;
    }

    printLess(n - 1);
    printf("%d", n);
    printLess(n - 1);
}
int main(void)
{
    int n;
    scanf("%d", &n);
    printLess(n);
    return 0;
}

// printLess(3)
// printLess(2)
// printLess(1) ->
// printLess(0)

// 1213121
