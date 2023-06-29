#include <stdio.h>

void add_array(double source[], double source2[], double target[], int num);
int main(void)
{

    int value;
    double doubleArray_1[100] = {0};
    double doubleArray_2[100] = {0};
    double targetArray[100] = {0};

    scanf("%d", &value);

    for (int i = 0; i < value; i++)
    {
        scanf("%lf", &doubleArray_1[i]);
    }

    for (int i = 0; i < value; i++)
    {
        scanf("%lf", &doubleArray_2[i]);
    }

    add_array(doubleArray_1, doubleArray_2, targetArray, value);

    for (int i = 0; i < value; i++)
    {
        printf("%.2lf ", targetArray[i]);
    }
    return 0;
}

void add_array(double source[], double source2[], double target[], int num)
{
    for (int i = 0; i < num; i++)
    {
        target[i] = source[i] + source2[i];
    }
}
