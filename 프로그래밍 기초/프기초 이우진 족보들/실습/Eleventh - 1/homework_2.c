#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    typedef enum Week_
    {
        FRI,
        SAT,
        SUN,
        MON,
        TUE,
        WED,
        THU,
    } Day;

    // TODO: 2021년 5월 날짜 추측
    // 2021년 5월 1일 -> 토요일

    int value;
    scanf("%d", &value);

    // 만약 dayNumber가 1이면 토 -> 쭉 간다
    Day today = (value - 210500) % 7;
    /*
        1->토
        2->일
        3->월
        4->화
        5->수
        6->목
        7->금
    */

    switch (today)
    {
    case SAT:
        printf("SAT\nWEEKEND");
        break;
    case SUN:
        printf("SUN\nWEEKEND");
        break;
    case MON:
        printf("MON\nWEEKDAY");
        break;
    case TUE:
        printf("TUE\nWEEKDAY");
        break;
    case WED:
        printf("WED\nWEEKDAY");
        break;
    case THU:
        printf("THU\nWEEKDAY");
        break;
    case FRI:
        printf("FRI\nWEEKDAY");
        break;
    }

    return 0;
}