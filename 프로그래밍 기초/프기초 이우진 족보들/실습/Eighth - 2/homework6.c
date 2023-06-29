#include <stdio.h>
#include <math.h>

void printArr(int intArr[], int count)
{
    printf("arr[%d] = ", count);
}

int main(void)
{

    int intArr[100] = {0};
    int count = 0;
    while (1)
    {

        int inputValue;
        scanf("%d", &inputValue);

        if (inputValue == 0)
        {
            break;
        }
        else if (inputValue > 0)
        {
            if (intArr[inputValue] == 0)
            {
                intArr[inputValue] = 1;
                count++;
                printArr(intArr, count);
            }
            else
            {
                intArr[inputValue]++;
            }
        }
        else
        {
            int absInt = abs(inputValue);
            intArr[absInt]--;
        }
    }
}