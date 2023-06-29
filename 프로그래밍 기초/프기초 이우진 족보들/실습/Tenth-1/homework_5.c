#include <stdio.h>
#define MAXBUFSIZE 100

void print1DArray(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(void)
{
    int i, j;
    // 크기가 4인 포인터 배열을 선언한다.
    int *p[4] = {
        NULL,
    };

    int a[4][5];

    // 4 * 5 배열을 입력받는다.
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    int count_1 = 2; // 짝수
    int count_2 = 0; // 홀수
    for (int i = 0; i < 4; i++)
    {
        if (i % 2 == 0)
        {
            p[count_1] = a[i];
            count_1++;
        }
        else
        {
            p[count_2] = a[i];
            count_2++;
        }
    }

    // 4 * 5 배열을 출력한다.
    for (i = 0; i < 4; i++)
    {
        print1DArray(p[i], 5);
    }

    return 0;
}