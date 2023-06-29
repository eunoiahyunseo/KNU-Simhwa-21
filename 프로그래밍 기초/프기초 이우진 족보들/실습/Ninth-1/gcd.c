#include <stdio.h>

int gcd(int max, int min)
{
    // 애초에 max는 min 보다 작지 않은 수로 가정하는 것이다.
    if (min == 0)
    {
        return max;
    }
    else
    {
        return gcd(min, max % min);
    }
}
int main(void)
{
    int value1 = 30;
    int value2 = 25;

    printf("gcd(%d, %d) >> %d\n", value1, value2, gcd(value1, value2));

    return 0;
}