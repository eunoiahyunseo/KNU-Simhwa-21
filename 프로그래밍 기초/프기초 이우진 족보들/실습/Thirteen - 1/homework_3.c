#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main(void)
{
    FILE *fp_read;
    char inputFileName[100] = {0};
    int i, j;

    int *p[MAX];
    // 그냥 value * value 2차원배열을 받겠다는 의미
    int value;

    gets(inputFileName);

    fp_read = fopen(inputFileName, "r");

    fscanf(fp_read, "%d", &value);

    for (i = 0; i < value; i++)
    {
        p[i] = malloc(sizeof(int) * value);
        for (j = 0; j < value; j++)
        {
            fscanf(fp_read, "%d", &p[i][j]);
        }
    }

    int min = p[0][0];
    for (i = 0; i < value; i++)
    {
        for (j = 0; j < value; j++)
        {
            if (min > p[i][j])
            {
                min = p[i][j];
            }
        }
    }

    for (i = 0; i < value; i++)
    {
        free(p[i]);
    }

    printf("%d", min);

    return 0;
}