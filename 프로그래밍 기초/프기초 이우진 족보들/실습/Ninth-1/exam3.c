#include <stdio.h>

int checkTwins(int a);

void main()
{

    int input;

    while (1)
    {
        scanf("%d", &input);

        if (input == 0)
            break;

        if (checkTwins(input) == -1)
            printf("no\n");

        else if (checkTwins(input) == 1)
            printf("yes\n");
    }
}

int checkTwins(int a)
{

    int x, y;

    x = a % 10;
    y = a / 10 % 10;

    if (a < 10)
        return 1;

    if (x != y)
        return -1;

    else
        checkTwins(a / 100);
}