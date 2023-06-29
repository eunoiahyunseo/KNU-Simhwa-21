#include <iostream>
#include <cmath>
#include "mathlib.h"

using namespace std;
int max(int a, int b)
{
    if (a >= b)
    {
        return a;
    }
    return b;
}

int min(int a, int b)
{
    if (a <= b)
    {
        return a;
    }
    return b;
}

int max(int arr[], int n)
{
    int max_ = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max_ < arr[i])
        {
            max_ = arr[i];
        }
    }
    return max_;
}

int min(int arr[], int n)
{
    int min_ = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (min_ > arr[i])
        {
            min_ = arr[i];
        }
    }
    return min_;
}

float square(float x)
{
    return sqrt(x);
}

void square(float arrOut[], const float arrIn[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arrOut[i] = sqrt(arrIn[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << "arrOut[" << i << "] => " << arrOut[i] << endl;
    }
}

int main(void)
{
    int max_value = max(1, 3);
    cout << "max_value => " << max_value << endl;

    int min_value = min(1, 3);
    cout << "min_value => " << min_value << endl;

    int arr[] = {3, 4, 0, 9, 2, 6, 7, 1};
    int count_arr = sizeof(arr) / sizeof(int);

    int max_value_arr = max(arr, count_arr);
    cout << "max_value_inArr => " << max_value_arr << endl;

    int min_value_arr = min(arr, count_arr);
    cout << "min_value_inArr => " << min_value_arr << endl;

    float number_sqrt = 9;
    cout << "sqrt_float_value => " << sqrt(number_sqrt) << endl;

    int n = 5;
    const float arr_[] = {1.f, 2.f, 3.f, 4.f, 5.f};
    float arrSquared[n];

    square(arrSquared, arr_, n);

    return 0;
}
