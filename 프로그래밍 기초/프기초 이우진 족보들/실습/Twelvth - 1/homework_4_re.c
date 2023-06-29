#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct account_
{
    int accNum;
    char name[30];
    double balance;
} account;

static account accountList[100] = {0};
static int count = 0;
static FILE *fp_write;
static FILE *fp_read;

void add();
void search();
void deposit();
void withdraw();
void printAll();
void saveOutputFile();

int main(void)
{
    int i, size;

    // 기존의 파일이 존재 하게 된다면
    // 파일의 값을 가져온다.
    if ((fp_read = fopen("bank.bin", "rb")) != NULL)
    {
        fseek(fp_read, 0, SEEK_END);
        size = ftell(fp_read);
        rewind(fp_read);

        if (size != 0)
        {
            while (fread(accountList + count, sizeof(accountList[count]), 1, fp_read) != 0)
            {
                count++;
            }
        }
        fclose(fp_read);
    }

    while (1)
    {
        int value;
        scanf("%d", &value);

        if (value == -1)
        {
            break;
        }
        else if (value == 1)
        {
            add();
        }
        else if (value == 2)
        {
            search();
        }
        else if (value == 3)
        {
            deposit();
        }
        else if (value == 4)
        {
            withdraw();
        }
        else if (value == 5)
        {
            printAll();
        }
        else if (value == 6)
        {
            saveOutputFile();
            break;
        }
    }
    return 0;
}

void add()
{
    int temp;
    while (1)
    {
        scanf("%d", &temp);
        if (temp < 0)
        {
            break;
        }
        accountList[count].accNum = temp;
        scanf("%s %lf", accountList[count].name, &accountList[count].balance);
        count++;
    }
}

void search()
{
    char searchName[100];
    scanf("%s", searchName);
    int i;

    for (i = 0; i < count; i++)
    {
        // 검색하고자 하는 이름을 가진 계좌를 찾았다면
        if (!strcmp(accountList[i].name, searchName))
        {
            printf("%d %s %.2lf\n", accountList[i].accNum, accountList[i].name, accountList[i].balance);
        }
    }
}

void deposit()
{
    char editName[100];
    double depositMoney;
    scanf("%s %lf", editName, &depositMoney);
    for (int i = 0; i < count; i++)
    {
        if (!strcmp(accountList[i].name, editName))
        {
            accountList[i].balance += depositMoney;
            printf("%d %s %.2lf\n", accountList[i].accNum, accountList[i].name, accountList[i].balance);
        }
    }
}

void withdraw()
{
    char editName[100];
    double withDrawMoney;
    scanf("%s %lf", editName, &withDrawMoney);
    for (int i = 0; i < count; i++)
    {
        if (!strcmp(accountList[i].name, editName))
        {
            accountList[i].balance -= withDrawMoney;
            printf("%d %s %.2lf\n", accountList[i].accNum, accountList[i].name, accountList[i].balance);
        }
    }
}

void printAll()
{
    double Total = 0;
    for (int i = 0; i < count; i++)
    {
        Total += accountList[i].balance;
    }
    printf("Total=%.2lf\n", Total);
    for (int i = 0; i < count; i++)
    {
        printf("%d %s %.2lf\n", accountList[i].accNum, accountList[i].name, accountList[i].balance);
    }
}

void saveOutputFile()
{
    if ((fp_write = fopen("bank.bin", "wb")) == NULL)
    {
        printf("Error");
        exit(0);
    }

    fwrite(accountList, sizeof(account), count, fp_write);
    fclose(fp_write);
}