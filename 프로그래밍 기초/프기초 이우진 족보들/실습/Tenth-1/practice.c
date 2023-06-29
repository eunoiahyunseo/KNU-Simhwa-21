#include <stdio.h>

void hello()
{
    printf("Hello, world!\n");
}

void bonjour()
{
    printf("bonjour le monde!\n");
}

int main(void)
{
    // int tAry[][3] = {{1, 2, 3}, {4, 5, 6}};

    // printf("sizeof(tAry) >> %lu\n", sizeof(tAry));
    // printf("sizeof(tAry[0]) >> %lu\n", sizeof(tAry[0]));
    // printf("sizeof(tAray[0][0]) >> %lu\n", sizeof(tAry[0][0]));

    // printf("\n");

    // printf("*(tAray[0] + 1) >> %d\n", *(tAry[0] + 1));
    // printf("tAry[0] >> %p\n", tAry[0]);
    // printf("*tAry >> %p\n", *tAry);

    // printf("\n");

    // printf("&tAry[0][1] >> %p\n", &tAry[0][1]);
    // printf("tAry[0] + 1 >> %p\n", tAry[0] + 1);

    // printf("**(tAry + 1) >> %d\n", **(tAry + 1));

    // < 함수 포인터 >

    // void (*fp)(); // 반환값과 매개변수가 없는 함수 포인터 fp 선언
    // fp = hello;
    // fp();
    // fp = bonjour;
    // fp();
    // return 0;

    // 배열의 길이는 알 수 없으므로 함수 이런데 전달하려면 직접 전달해 주어야 한다
    int tAry[][3] = {{1, 2, 3}, {4, 5, 6}};
    int(*AryPointer)[3] = tAry;

    printf("sizeof(AryPointer) >> %lu\n", sizeof(AryPointer));
    printf("sizeof(AryPointer[0]) >> %lu\n", sizeof(AryPointer[0]));
    printf("sizeof(AryPointer[0]) >> %lu\n", sizeof(AryPointer[0]));
    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < sizeof(AryPointer[0]) / sizeof(*AryPointer[0]); i++)
        {
            printf("%d ", AryPointer[j][i]);
        }
        printf("\n");
    }

    // 포인터는 주의해서 사용한다
    // 또한 포인터는 다 쓰고 NULL로 초기화 시켜주어 추후에 포인터 사용에
    // 조심해야 한다.
}
