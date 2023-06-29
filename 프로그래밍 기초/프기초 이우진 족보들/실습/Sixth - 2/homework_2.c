#include <stdio.h>

int main(void)
{

    while (1)
    {
        int value;
        scanf("%d", &value);
        if (value == -1)
        {
            break;
        }
        int div_value = value / 10;
        if (div_value > 9)
        {
            div_value = 9;
        }

        switch (div_value)
        {
        case (9):
            printf("A\n");
            break;
        case (8):
            printf("B\n");
            break;
        case (7):
            printf("C\n");
            break;
        case (6):
            printf("D\n");
            break;
        default:
            printf("F\n");
            break;
        }
    }
    return 0;
}