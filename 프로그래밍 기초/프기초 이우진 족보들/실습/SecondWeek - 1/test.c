#include <stdio.h>

int main()
{
    double x = 5.1247;
    double y = 20.7807;
    double z = 17.34;

    printf("%f %f %f\n", x, y, z);
    printf("%f\n", x + y + z);
    printf("%f\n", x - y - z);
    printf("%f\n", x / y / z);
    printf("%f", (x * y) / z);

    return 0;
}