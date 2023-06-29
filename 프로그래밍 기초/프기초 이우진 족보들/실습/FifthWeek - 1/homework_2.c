#include <stdio.h>

int main(void)
{

    int value;
    int first_money = 1;
    int sum = 0;
    while (1)
    {
        scanf("%d", &value);
        if (value < 0)
        {
            printf("%s\n", "wrong");
        }
        else
        {
            for (int i = 0; i < value; i++)
            {
                printf("%d\n", first_money);
                sum += first_money;
                first_money *= 2;
            }
            break;
        }
    }
    printf("=%d\n", sum);
}