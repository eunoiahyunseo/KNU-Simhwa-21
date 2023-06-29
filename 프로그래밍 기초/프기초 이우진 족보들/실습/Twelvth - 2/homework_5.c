#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 날짜 구조체
typedef struct Day_
{
    int year;
    int month;
    int day;
} Day;

// 입력받은 날짜를 하루 증가시켜 새로운 날짜를 구하는 작업을 함수로 구현한다.
// 함수는 년, 월, 일의 3가지 필드를 가지는 날짜 구조체를 매개변수로 받고 날짜가 하루 경과된 새로운 날짜 구조체를 반환한다.

// 함수 선언
Day plusDay(Day today)
{
    Day tommorow;
    int isYoonYear = -1;

    // 윤년이 아닌경우
    if (!(((today.year % 4 == 0) && (today.year % 100 != 0)) || today.year % 400 == 0))
    {
        // 윤년이 아니라면 1이다. 윤년이라면 -1
        isYoonYear = 1;
    }

    switch (today.month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        // CORNERCASE: 날짜가 1과 31일 사이인가 check
        if (today.day >= 1 && today.day <= 31)
        {
            // CASE1: 12월 31일
            if ((today.day == 31) && (today.month == 12))
            {

                tommorow.year = today.year + 1;
                tommorow.month = 13 - today.month;
                tommorow.day = 1;
            }
            // CASE2: 12월 31일 이외의 31일
            else if ((today.day == 31) && (today.month != 12))
            {
                tommorow.year = today.year;
                tommorow.month = today.month + 1;
                tommorow.day = 1;
            }
            // CASE3: 31일을 제외한 다른 일자
            else
            {
                tommorow.year = today.year;
                tommorow.month = today.month;
                tommorow.day = today.day + 1;
            }
        }
        // 범위 밖이면 그냥 다 0으로 처리
        else
        {
            tommorow.year = 0;
            tommorow.month = 0;
            tommorow.day = 0;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        // CORNERCASE: 날짜가 1과 31일 사이인가 check
        if (today.day >= 1 && today.day <= 30)
        {
            // CASE1: 30일
            if (today.day == 30)
            {
                tommorow.year = today.year;
                tommorow.month = today.month + 1;
                tommorow.day = 1;
            }
            // CASE3: 30일을 제외한 다른 일자
            else
            {
                tommorow.year = today.year;
                tommorow.month = today.month;
                tommorow.day = today.day + 1;
            }
        }
        // 범위 밖이면 그냥 다 0으로 처리
        else
        {
            tommorow.year = 0;
            tommorow.month = 0;
            tommorow.day = 0;
        }
        break;
    case 2:
        // 윤년인데 마지막 이면
        if ((isYoonYear == -1) && (today.day == 29))
        {
            tommorow.year = today.year;
            tommorow.month = today.month + 1;
            tommorow.day = 1;
        }
        else if ((isYoonYear == -1) && (today.day != 29))
        {
            tommorow.year = today.year;
            tommorow.month = today.month;
            tommorow.day = today.day + 1;
        }
        else if ((isYoonYear == 1) && (today.day == 28))
        {
            tommorow.year = today.year;
            tommorow.month = today.month + 1;
            tommorow.day = 1;
        }
        else if ((isYoonYear == 1) && (today.day != 28))
        {
            tommorow.year = today.year;
            tommorow.month = today.month;
            tommorow.day = today.day + 1;
        }
        break;
    default:
        break;
    }
    return tommorow;
}

int main(void)
{
    char inputFileName[100] = {0};
    char outputFileName[100] = {0};

    scanf("%s %s", inputFileName, outputFileName);
    Day today;

    FILE *fp_read;
    if ((fp_read = fopen(inputFileName, "r")) == NULL)
    {
        printf("error Occured in fileOpen");
        exit(0);
    }

    fscanf(fp_read, "%d %d %d", &today.year, &today.month, &today.day);
    fclose(fp_read);

    Day tommrow = plusDay(today);

    FILE *fp_write;
    char errorMsg[100] = "wrong input";
    if ((fp_write = fopen(outputFileName, "w")) == NULL)
    {
        printf("error Ocrured in fileWirte");
        exit(0);
    }

    if ((tommrow.year == 0) && (tommrow.month == 0) && (tommrow.day == 0))
    {
        fprintf(fp_write, "%s", errorMsg);
    }
    else
    {
        fprintf(fp_write, "%d.%d.%d", tommrow.year, tommrow.month, tommrow.day);
    }
    fclose(fp_write);

    return 0;
}