#include <stdio.h>

void hanoi_tower(int n, int from, int to)
{
    int middle = 6 - (from + to);
    if (n == 1)
    {
        printf("disk[%d] >> %d->%d\n", n, from, to);
    }
    else if (n >= 2)
    {
        hanoi_tower(n - 1, from, middle);
        // hanoi_tower(1, from, to);
        printf("disk[%d] >> %d->%d\n", n, from, to);
        hanoi_tower(n - 1, middle, to);
    }
}

void hanoi_tower_E(int n, int from, int to)
{
    int middle = 6 - (from + to);
    if (n % 2 == 0)
    {
        if (n <= 0)
        {
            return;
        }
        hanoi_tower(n - 1, from, to);
        printf("disk[%d] >> %d->%d\n", n, from, middle);
        hanoi_tower(n - 2, to, from);
        hanoi_tower_E(n - 2, from, to);
    }
}

int main(void)
{
    int value;
    scanf("%d", &value);
    // printf("%d\n", (1 << value) - 1);
    hanoi_tower_E(value, 1, 3);
    return 0;
}