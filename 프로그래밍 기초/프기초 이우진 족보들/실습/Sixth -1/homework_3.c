#include <stdio.h>

int isPrime(int x)
{
    int count = 0;
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
        {
            count += 1;
            break;
        }
    }
    if (count > 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main(void)
{
    int value;
    scanf("%d", &value);
    printf("%s\n", isPrime(x) ? "prime" : "not prime");
}