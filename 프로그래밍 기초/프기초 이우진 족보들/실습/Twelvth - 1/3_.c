
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct account_
{
    int accNum;
    char name[30];
    double balance;
} account;

account accountList[100] = {0};

void add();

int main(void)
{
    // 고객들의 은행 계좌정보를 구조체 account를 이용해서 이진파일에 저장한다
    // 이 떄 이진 파일 이름은 bank.bin으로 한다.
    // 그리고 해당 계좌 파일을 이용하여 고객들의 계좌 정보를 추가. 검색, 입금, 출금, 출력
    // 할 수 있는 메뉴 기반의 프로그램을 작성하시오

    // 크기 100인 계좌구조체 배열을 선언하고 0으로 초기화 한다.

    // 파일이 없다면 새로 만들고, 기존의 파일이 있으면 그 파일의 가장 뒤부터 파일에 추가한다.
    // 파일의 어느 곳이나 읽기는 가능하나 쓰기는 파일 끝에 추가적으로만 가능하다.
    FILE *fp_write = fopen("bank.bin", "wb");
    FILE *fp_read = fopen("bank.bin", "rb");
    FILE *fp_read_1;

    // 전역으로 만들어 준다. -> 없어지는 정보가 아니니까
    int count = 0;
    int i, size;

    // 기존에 파일이 있다면 읽어 온다.
    // NULL이 아닌 동안
    if ((fp_read_1 = fopen("bank.bin", "rb+")) != NULL)
    {
        fseek(fp_read_1, 0, SEEK_END);
        size = ftell(fp_read_1);
        rewind(fp_read_1);
        // 기존의 파일이 있다면
        if (size != 0)
        {
            while (fread(accountList + count, sizeof(accountList[count]), 1, fp_read_1) != 0)
            {
                count++;
            }
        }
        fclose(fp_read_1);
    }

    while (1)
    {
        int value;
        scanf("%d", &value);

        if (value == -1)
        {
            break;
        }
        else
        {
            // value == 1이라면 계좌를 추가 한다.
            if (value == 1)
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
            // value == 2이라면 계좌를 검색한다.
            else if (value == 2)
            {
                char searchName[100];
                scanf("%s", searchName);

                account *searchAccount = (account *)malloc(sizeof(account));

                for (i = 0; i < count; i++)
                {
                    // 검색하고자 하는 이름을 가진 계좌를 찾았다면
                    if (!strcmp(accountList[i].name, searchName))
                    {
                        printf("%d %s %.2lf\n", accountList[i].accNum, accountList[i].name, accountList[i].balance);
                    }
                }
            }
            // value == 3이라면 입금한다.
            else if (value == 3)
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
            // value == 4이라면 출금한다.
            else if (value == 4)
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
            // value == 5이라면 출력한다.
            else if (value == 5)
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
            // value == 6이라면 종료한다.
            else if (value == 6)
            {
                fwrite(accountList, sizeof(account), count, fp_write);
                fclose(fp_write);
                break;
            }
        }
    }

    return 0;
}
