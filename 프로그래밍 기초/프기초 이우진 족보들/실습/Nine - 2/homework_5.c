#include <stdio.h>

void sortWithoutDuplication(int array[], int *size)
{
    int newArr[*size];
    for (int i = 0; i < *size; i++)
    {
        for (int j = 0; j < *size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < *size; i++)
    {
        for (int j = i + 1; j < *size; j++)
        {
            if (array[i] == array[j])
            {
                for (int k = j; k < *size - 1; k++)
                {
                    array[k] = array[k + 1];
                }
                *size -= 1;
                j--;
            }
        }
    }
}

int main(void)
{
    int length = 10;
    int intArr[length];

    for (int i = 0; i < length; i++)
    {
        scanf("%d", &intArr[i]);
    }

    sortWithoutDuplication(intArr, &length);

    for (int i = 0; i < length; i++)
    {
        printf("%d ", intArr[i]);
    }

    return 0;
}