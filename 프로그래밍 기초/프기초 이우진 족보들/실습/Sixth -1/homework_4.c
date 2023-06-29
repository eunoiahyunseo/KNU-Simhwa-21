#include <stdio.h>
int sumMultiple(int start, int end, int x)
{
    int sum = 0;
    for (int i = start; i < end; i++)
    {
        if (i % x == 0)
        {
            sum += i;
        }
    }
    return sum;
}

int sumMultiple_version2(int start, int end, int n, int m)
{
    int sum = 0;
    for (int i = start; i < end; i++)
    {
        if ((i % n == 0) || (i % m == 0))
        {
            sum += i;
        }
    }
    return sum;
}

int sumMultiple_version3(int start, int end, int n, int m)
{
    int sum = 0;
    for (int i = start; i < end; i++)
    {
        if ((i % m == 0) && (i % n != 0))
        {
            sum += i;
        }
    }
    return sum;
}

int sumMultiple_version4(int start, int end, int n, int m)
{
    int sum = 0;
    for (int i = start; i < end; i++)
    {
        if ((i % m != 0) && (i % n != 0))
        {
            sum += i;
        }
    }
    return sum;
}
int main(void)
{
    int start, end, n, m;
    scanf("%d %d %d %d", &start, &end, &n, &m);

    printf("%d\n", sumMultiple(start, end, n));
    printf("%d\n", sumMultiple(start, end, m));
    printf("%d\n", sumMultiple(start, end, m * n));
    printf("%d\n", sumMultiple_version2(start, end, n, m));
    printf("%d\n", sumMultiple_version3(start, end, n, m));
    printf("%d\n", sumMultiple_version4(start, end, n, m));

    return 0;
}