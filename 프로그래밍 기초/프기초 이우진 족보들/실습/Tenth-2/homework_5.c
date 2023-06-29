#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char fname[100];
    int calories;
} Food;

int totalCalories(Food ary[], int size);

int main(void)
{
    Food foodAry[100] = {0};
    int count = 0;

    while (1)
    {
        scanf("%s", foodAry[count].fname);
        if (strcmp(foodAry[count].fname, "quit") == 0) // quit이 나오면 그만한다.
        {
            break;
        }
        else
        {
            scanf("%d", &foodAry[count].calories);
            count++;
        }
    }
    printf("%d", totalCalories(foodAry, count));

    return 0;
}

int totalCalories(Food ary[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += ary[i].calories;
    }
    return sum;
}