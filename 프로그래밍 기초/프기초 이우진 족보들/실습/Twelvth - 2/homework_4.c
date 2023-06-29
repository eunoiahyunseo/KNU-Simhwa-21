#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Money_
{
    char money[8][100];
    int moneyCount[8];
} Money, *ptrMoney;

void countMoney(ptrMoney ptrFirstMoneyCount, int inputValue)
{
    ptrFirstMoneyCount->moneyCount[0] = inputValue / 50000;
    inputValue -= ptrFirstMoneyCount->moneyCount[0] * 50000;
    ptrFirstMoneyCount->moneyCount[1] = inputValue / 10000;
    inputValue -= ptrFirstMoneyCount->moneyCount[1] * 10000;
    ptrFirstMoneyCount->moneyCount[2] = inputValue / 5000;
    inputValue -= ptrFirstMoneyCount->moneyCount[2] * 5000;
    ptrFirstMoneyCount->moneyCount[3] = inputValue / 1000;
    inputValue -= ptrFirstMoneyCount->moneyCount[3] * 1000;
    ptrFirstMoneyCount->moneyCount[4] = inputValue / 500;
    inputValue -= ptrFirstMoneyCount->moneyCount[4] * 500;
    ptrFirstMoneyCount->moneyCount[5] = inputValue / 100;
    inputValue -= ptrFirstMoneyCount->moneyCount[5] * 100;
    ptrFirstMoneyCount->moneyCount[6] = inputValue / 50;
    inputValue -= ptrFirstMoneyCount->moneyCount[6] * 50;
    ptrFirstMoneyCount->moneyCount[7] = inputValue / 10;

    strcpy(ptrFirstMoneyCount->money[0], "50,000");
    strcpy(ptrFirstMoneyCount->money[1], "10,000");
    strcpy(ptrFirstMoneyCount->money[2], "5,000");
    strcpy(ptrFirstMoneyCount->money[3], "1,000");
    strcpy(ptrFirstMoneyCount->money[4], "500");
    strcpy(ptrFirstMoneyCount->money[5], "100");
    strcpy(ptrFirstMoneyCount->money[6], "50");
    strcpy(ptrFirstMoneyCount->money[7], "10");
}

int main(void)
{
    char inputFileName[100] = {0};
    char outputFileName[100] = {0};

    scanf("%s %s", inputFileName, outputFileName);
    int inputValue;

    FILE *fp_read;
    if ((fp_read = fopen(inputFileName, "r")) == NULL)
    {
        printf("error Occured in fileRead");
        exit(0);
    }

    fscanf(fp_read, "%d", &inputValue);
    fclose(fp_read);

    Money firstMoneyCount;
    // call by reference
    countMoney(&firstMoneyCount, inputValue);

    FILE *fp_write;
    if ((fp_write = fopen(outputFileName, "w")) == NULL)
    {
        printf("error Occured in fileWrite");
        exit(0);
    }

    for (int i = 0; i < 8; i++)
    {
        if (firstMoneyCount.moneyCount[i] != 0)
        {
            fprintf(fp_write, "%s:%d\n", firstMoneyCount.money[i], firstMoneyCount.moneyCount[i]);
        }
    }
    fclose(fp_write);

    return 0;
}