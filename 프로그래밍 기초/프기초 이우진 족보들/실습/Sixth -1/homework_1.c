#include <stdio.h>

int gcd(int a, int b)
{
    int tmp, n;
    if (a < b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }

    //유클리드 알고리즘 부분입니다.
    //b가 0이 될때까지(a%b), 반복문을 돌게되고, b가 0인 순간의 a를 GCD로 판단하고 리턴합니다.
    while (b != 0)
    {
        n = a % b;
        a = b;
        b = n;
    }
    return a;
}

int main(void)
{
    int value_1, value_2;
    scanf("%d %d", &value_1, &value_2);
    int gcd_ = gcd(value_1, value_2);
    printf("%d\n", gcd_);
    return 0;
}