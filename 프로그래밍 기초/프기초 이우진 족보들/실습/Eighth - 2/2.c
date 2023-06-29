#include <stdio.h>

void increment();
int main(void)
{

    increment();
    increment();
    increment();
    return 0;
}
void increment()
{
    static int sindex = 1; // 정적 지역 변수
    auto int aindex = 1;   // 자동 지역 변수

    printf("정적 지역변수 sindex=%2d,\t", sindex);
    printf("자동 지역변수 aindex=%2d,\n", aindex);
    sindex++;
    aindex++;
}

// strtok 에서도 string에 대한 정보를 저장하기 위해 static을 사용한다!!

// strtok(NULL, "") 여기서 NULL의 의미는 너가 내부적으로 kepping하고 있는
// 정보를 이요해서 다음 token을 tokenizer해 달라
