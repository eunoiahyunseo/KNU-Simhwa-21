#include <stdio.h>
#define MAX 100
int fibScore[MAX] = {0};

// 재귀(recursion)를 사용
// 비효율적인 알고리즘

int fib(unsigned int n);

int fib_2(unsigned int n);

int main(void)
{

    // 비 효율적인 재귀
    // int endNumber = 10;
    // printf("%d >> %d\n", endNumber, fib(endNumber));

    // 효율적인 재귀
    int endNumber = 28;
    printf("%d >> %d\n", endNumber, fib_2(endNumber));

    return 0;
}

// Fn = Fn-1 + Fn-2  F1 = 1 F0=0

// < fib version1 >>
int fib(unsigned int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}

// <fib version2 >>

// 메모라이 제이션 기법
int fib_2(unsigned int n)
{
    int i;
    if (n == 0 || n == 1)
    {
        return n;
    }

    fibScore[0] = 0;
    fibScore[1] = 1;

    for (i = 2; i <= n; i++)
    {
        fibScore[i] = fibScore[i - 1] + fibScore[i - 2];
    }

    return fibScore[n];
}
