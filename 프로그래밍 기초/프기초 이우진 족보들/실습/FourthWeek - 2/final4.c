#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Trip_
{
    // 날짜
    int month;
    int day;

    // 금액들
    char Content[100];
    int cost;
} Trip;

typedef struct tripTotal_
{
    int month;
    int cost;
} tripTotal;

int main(void)
{
    FILE *fp_read;
    // tripList
    int count = 0;

    // tripDaily
    int count2 = 0;

    // toptalList
    int count3 = 0;

    Trip tripList[100];
    Trip tripDaily[100];
    tripTotal totalList[100];

    memset(tripList, 0, sizeof(Trip) * 100);
    memset(tripDaily, 0, sizeof(Trip) * 100);
    memset(totalList, 0, sizeof(tripTotal) * 100);

    if ((fp_read = fopen("diary.txt", "r")) == NULL)
    {
        printf("error occured int open file");
    }

    while (fscanf(fp_read, "%d.%d %s %d", &tripList[count].month, &tripList[count].day, tripList[count].Content, &tripList[count].cost) != EOF)
    {
        count++;
    }

    tripDaily[0] = tripList[0];

    // 일별로 정렬되어 저장되어 있다했음
    for (int i = 1; i < count; i++)
    {
        // CASE1: 만약에 전과 같은 일자면
        if ((tripList[i].month == tripList[i - 1].month) && (tripList[i].day == tripList[i - 1].day))
        {
            // 이미 있는 거라면 그냥 가격만 추가해 주면 된다
            tripDaily[count2].cost += tripList[i].cost;
        }
        else
        {
            // CASE2: 만약에 같은 일자가 아니라면
            count2++;
            tripDaily[count2] = tripList[i];
        }
    }

    fclose(fp_read);

    printf("Daily\n");
    // count2 + 1만큼 반복을 해줘야 겠지
    for (int i = 0; i < count2 + 1; i++)
    {
        printf("%d.%d: %d\n", tripDaily[i].month, tripDaily[i].day, tripDaily[i].cost);
    }

    totalList[0].month = tripDaily[0].month;
    totalList[0].cost = tripDaily[0].cost;

    for (int i = 1; i < count2 + 1; i++)
    {
        // CASE1: 만약 달이 전과 같다면
        if (tripDaily[i].month == tripDaily[i - 1].month)
        {
            totalList[count3].cost += tripDaily[i].cost;
        }
        else
        {
            // CASE2: 만약 달이 전과 다르다면
            count3++;
            totalList[count3].month = tripDaily[i].month;
            totalList[count3].cost = tripDaily[i].cost;
        }
    }
    printf("\nMonthly\n");
    for (int i = 0; i < count3 + 1; i++)
    {
        printf("%d: %d\n", totalList[i].month, totalList[i].cost);
    }

    return 0;
}