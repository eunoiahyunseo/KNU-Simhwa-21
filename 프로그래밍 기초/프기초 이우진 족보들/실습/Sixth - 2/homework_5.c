#include <stdio.h>

void getJudgeData(double data[], int value)
{
    double min = data[0];
    for (int i = 0; i < value; i++)
    {
        if (data[i] < min)
        {
            min = data[i];
        }
    }
    double max = data[0];
    for (int i = 0; i < value; i++)
    {
        if (data[i] > max)
        {
            max = data[i];
        }
    }

    double sum = 0;
    int count = 0;
    for (int i = 0; i < value; i++)
    {
        if (data[i] == min || data[i] == max)
        {
            continue;
        }
        else
        {
            sum += data[i];
            count += 1;
        }
    }

    double avg;
    avg = sum / count;
    printf("%.2lf\n", avg);
}

int main(void)
{
    int value;
    int count = 0;
    double arr[100];
    scanf("%d", &value);

    while (1)
    {
        double value_2;
        scanf("%lf", &value_2);
        if (value_2 <= 10 && value_2 >= 0)
        {
            arr[count] = value_2;
            count += 1;

            if (count == value)
            {
                break;
            }
        }
    }
    getJudgeData(arr, value);

    return 0;
}