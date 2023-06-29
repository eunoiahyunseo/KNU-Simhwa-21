#include <stdio.h>

int main(void)
{
    char operator;
    int first_value;
    int second_value;
    int sum = 0;

    while (1)
    {
        scanf("%d", &first_value);
        scanf("%c", &operator);
        scanf("%d", &second_value);

        if (operator== '!')
        {
            break;
        }
        else
        {
            switch (operator)
            {
            case '+':
                printf("%d%c%d=%d\n", first_value, operator, second_value, first_value + second_value);
                break;
            case '-':
                printf("%d%c%d=%d\n", first_value, operator, second_value, first_value - second_value);
                break;
            case '/':
                if (second_value == 0)
                {
                    printf("Error\n");
                    break;
                }
                float value = (float)first_value / (float)second_value;
                printf("%d%c%d=%.2f\n", first_value, operator, second_value, value);
                break;
            case '*':
                printf("%d%c%d=%d\n", first_value, operator, second_value, first_value * second_value);
                break;
            }
        }
    }
}