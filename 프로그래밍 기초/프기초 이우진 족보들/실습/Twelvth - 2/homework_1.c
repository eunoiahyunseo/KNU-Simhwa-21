#include <stdio.h>
#include <stdlib.h>

typedef struct Time
{
    int hour;
    int min;
    int sec;
} TIME;

int main(void)
{
    FILE *fp_write;

    char inputFileName[100];
    TIME timeBuffer[3];

    gets(inputFileName);

    fp_write = fopen(inputFileName, "r");

    int count = 0;
    while (fscanf(fp_write, "%d:%d:%d", &timeBuffer[count].hour, &timeBuffer[count].min, &timeBuffer[count].sec) != EOF)
    {
        count++;
    }

    int beforeTotalSec = timeBuffer[0].hour * 60 * 60 + timeBuffer[0].min * 60 + timeBuffer[0].sec;
    int afterTotalSec = timeBuffer[1].hour * 60 * 60 + timeBuffer[1].min * 60 + timeBuffer[1].sec;

    int diffTotalSec = afterTotalSec - beforeTotalSec;

    timeBuffer[count].hour = (diffTotalSec / 3600);
    timeBuffer[count].min = (diffTotalSec % 3600) / 60;
    timeBuffer[count].sec = (diffTotalSec % 3600) % 60;

    printf("%02d:%02d:%02d", timeBuffer[count].hour, timeBuffer[count].min, timeBuffer[count].sec);
}
