#include <stdio.h>

int main(void)
{

    const int int_arr[][3] = {{1, 2, 3}, {4, 5, 6}};
    const int(*grade)[3];
    grade = int_arr;

    printf("%lu\n", sizeof(grade));
    for (int j = 0; j < 2; j++)
    {

        for (int i = 0; i < sizeof(*(grade + 0)) / sizeof(int); i++)
        {
            printf("%d ", *(*(grade + j) + i));
        }
        printf("\n");
    }

    return 0;
}