#include <stdio.h>
#include <math.h>

int calc_KE(int weight, int velocity)
{
    int KE;
    KE = (0.5) * weight * pow(velocity, 2);
    return KE;
}

int main(void)
{
    int KE;
    int weight, velocity;
    scanf("%d %d", &weight, &velocity);
    printf("%d", calc_KE(weight, velocity));

    return 0;
}