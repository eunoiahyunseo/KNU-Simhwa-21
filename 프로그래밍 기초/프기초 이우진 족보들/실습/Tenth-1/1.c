#include <stdio.h>
#include <string.h>

int increment1(int *num)
{
    // (*num)++; // -> 작동 잘 됨
    // *num++; // -> 작동이 안되는 이유는 주소값을 증가시켰기 때문임
}
int main(void)
{
    // int number = 6;
    // printf("increment1 함수 호출 전 number의 값 >> %d\n", number);
    // increment1(&number);
    // printf("increment1 함수 호출 후 number의 값 >> %d\n", number);

    // int i = 0, sum = 0, aryLength;
    // int point[] = {95, 88, 76, 54, 85, 33, 65, 78, 99, 82};
    // aryLength = sizeof(point) / sizeof(int);
    // for (i = 0; i < aryLength; i++)
    // {
    //     sum += *(point + i);
    //     // sum += *(point++); -> 가 안되는 이유는 상수값은 증가시킬 수 없기 때문
    // }
    // printf("메인에서 구한 합은 %d\n", sum);

    int i;
    char name[20], result[100];

    scanf("%s", name);

    for (i = 0; i < strlen(name); i++)
    {
        printf("%s\n", &name[i]);
    }

    for (i = 0; i < strlen(name); i++)
    {
        strcpy(result, "Header_");
        printf("%s\n", strcat(result, &name[i]));
    }

    return 0;
}