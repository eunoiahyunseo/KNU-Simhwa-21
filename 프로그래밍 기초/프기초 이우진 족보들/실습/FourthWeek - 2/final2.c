#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    while (1)
    {
        char operator[100] = {0};
        int value1, value2, result = 0;

        scanf("%s", operator);

        if (!strcmp(operator, "quit"))
        {
            break;
        }
        scanf("%d %d", &value1, &value2);

        if (!strcmp(operator, "plus"))
        {
            result = value1 + value2;
            printf("%d\n", result);
        }
        else if (!strcmp(operator, "minus"))
        {
            result = value1 - value2;
            printf("%d\n", result);
        }
        else if (!strcmp(operator, "divide"))
        {
            if (value2 == 0)
            {
                printf("Divide-by-Zero\n");
                continue;
            }
            result = value1 / value2;
            printf("%d\n", result);
        }
        else
        {
            printf("Invalid Operator\n");
        }
    }
    return 0;
}