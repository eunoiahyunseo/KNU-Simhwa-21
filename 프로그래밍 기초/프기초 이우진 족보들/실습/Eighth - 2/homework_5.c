#include <stdio.h>

void printArr(int inputArr[], int count)
{
    printf("array[%d] = { ", count);
    for (int i = 0; i < count; i++)
    {
        printf("%d ", inputArr[i]);
    }
    printf("}\n");
}

int main(void)
{

    int inputArr[100] = {0};
    int count = 0;

    while (1)
    {
        int number;
        int search = -1;
        int search_index = -1;
        scanf("%d", &number);

        if (number == 0)
        {
            break;
        }
        else if (number > 0)
        {
            for (int i = 0; i < count; i++)
            {
                if (inputArr[i] == number)
                {
                    // 만약 inputArr 배열에 number가 존재 하면
                    // search > 0을 만들어 준다 만약 없다면 search = 0;
                    search++;
                    break;
                }
            }

            // 만약 주어진 배열에 numebr가 없다면 count에 해당하는 index에
            // number를 대입하고 count를 증가 시켜 준다.
            // count는 주어진 배열의 길이와 동일한 의미를 가지게 된다.
            if (search == -1)
            {
                inputArr[count] = number;
                count++;
            }
            printArr(inputArr, count);
        }
        else
        {
            int absNumber = (-1) * number;
            for (int i = 0; i < count; i++)
            {
                if (inputArr[i] == absNumber)
                {
                    search_index = i;
                }
            }
            if (search_index != -1)
            {
                for (int i = search_index; i < count; i++)
                {
                    inputArr[i] = inputArr[i + 1];
                }
                count--;
            }

            printArr(inputArr, count);
        }
    }

    return 0;
}