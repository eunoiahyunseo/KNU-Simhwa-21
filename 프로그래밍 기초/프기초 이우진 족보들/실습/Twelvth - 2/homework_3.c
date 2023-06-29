#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define VALUE 3

void bubbleSort(int orderBuffer[])
{
    for (int i = 0; i < VALUE; i++)
    {
        for (int j = 0; j < VALUE - i - 1; j++)
        {
            if (orderBuffer[j] > orderBuffer[j + 1])
            {
                int temp = orderBuffer[j];
                orderBuffer[j] = orderBuffer[j + 1];
                orderBuffer[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
    char inputFileName[100];
    gets(inputFileName);

    FILE *fp_write;

    // 사용자로부터 삼각형의 3변의 길이와 출력 파일 이름을 입력받아 삼각형 유형을 결정하여
    // 텍스트 파일로 출력하는 프로그램을 작성하라

    int first_value, second_value, third_value;

    // 길이 순서대로 삼각형의 변의 길이가 저장된다. -> 오름차순
    int orderBuffer[VALUE];
    memset(orderBuffer, 0, VALUE * sizeof(int));
    scanf("%d %d %d", &orderBuffer[0], &orderBuffer[1], &orderBuffer[2]);

    bubbleSort(orderBuffer);

    char outputFileBuffer[100] = {0};

    // CORNER CASE: 어떠한 한 값이 음수라면 이건 삼각형이 아니다.
    if ((orderBuffer[0] <= 0) || (orderBuffer[1] <= 0) || (orderBuffer[2] <= 0))
    {
        strcpy(outputFileBuffer, "Not Triangle");
    }
    // CASE1: 만약 가장 큰 값이 작은 두개의 값보다 작거나 같으면 삼각형이 아님
    else if (orderBuffer[2] >= orderBuffer[1] + orderBuffer[0])
    {
        strcpy(outputFileBuffer, "Not Triangle");
    }
    // CASE2: 정삼각형 -> 모든 변의 길이가 같으면
    else if ((orderBuffer[0] == orderBuffer[1]) && (orderBuffer[1] == orderBuffer[2]))
    {
        strcpy(outputFileBuffer, "Regular Triangle");
    }
    else if (orderBuffer[1] == orderBuffer[2])
    {
        // CASE3: 이등변 삼각형 -> 큰 두개의 변의 길이가 같음
        strcpy(outputFileBuffer, "Isosceles Triangle");
    }
    else
    {
        strcpy(outputFileBuffer, "General Triangle");
    }

    if ((fp_write = fopen(inputFileName, "w")) == NULL)
    {
        printf("error Occured in writeFile");
        exit(0);
    }

    fputs(outputFileBuffer, fp_write);

    fclose(fp_write);

    return 0;
}
