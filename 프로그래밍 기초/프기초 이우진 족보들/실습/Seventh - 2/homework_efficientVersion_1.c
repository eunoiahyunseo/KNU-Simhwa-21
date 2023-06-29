#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *name = malloc(sizeof(char) * 30);
    for (int i = 0; i < 4; i++)
    {
        int value_1, value_2, value_3;
        scanf("%s %d %d %d", name, &value_1, &value_2, &value_3);
        printf("%s %d %d %d %d\n", name, value_1, value_2, value_3, value_1 + value_2 + value_3);
    }

    free(name);
}