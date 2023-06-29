#include <stdio.h>

int main(void)
{

    int data[5] = {5, 2, 3, 1, 4};

    for (int i = 0; i < sizeof(data) / sizeof(int); i++)
    {

        for (int j = i + 1; j < sizeof(data) / sizeof(int); j++)
        {
            if (data[i] > data[j])
            {
                int temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", data[i]);
    }

    return 0;
}