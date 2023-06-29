#include <stdio.h>
#include <string.h>

typedef struct account
{
    int num;
    char name[30];
    double balance;
} account;

int main()
{
    FILE *fp = fopen("bank.bin", "wb");
    int menu = 0;
    account acc[100] = {0};
    char name[30] = {0};
    int cnt = 0;
    double total = 0;
    double got;
    while (1)
    {
        scanf("%d", &menu);
        // fscanf(stdin, "%d", &menu);
        if (menu == 1)
        {
            while (1)
            {
                printf("doing_1\n");
                scanf("%d %s %lf", &acc[cnt].num, acc[cnt].name, &acc[cnt].balance);
                if (acc[cnt].num == -1)
                {
                    break;
                }
                cnt++;
            }
        }
        else if (menu == 2)
        {
            scanf(" %s", name);
            for (int i = 0; i < cnt; i++)
            {
                if (strcmp(name, acc[i].name) == 0)
                {
                    printf("%d %s %.2lf\n", acc[i].num, acc[i].name, acc[i].balance);
                }
            }
        }
        else if (menu == 3)
        {
            scanf(" %s %lf", name, &got);
            for (int i = 0; i < cnt; i++)
            {
                if (strcmp(name, acc[i].name) == 0)
                {
                    acc[i].balance += got;
                    printf("%d %s %.2lf\n", acc[i].num, acc[i].name, acc[i].balance);
                }
            }
        }
        else if (menu == 4)
        {
            scanf(" %s %lf", name, &got);
            for (int i = 0; i < cnt; i++)
            {
                if (strcmp(name, acc[i].name) == 0)
                {
                    acc[i].balance -= got;
                    printf("%d %s %.2lf\n", acc[i].num, acc[i].name, acc[i].balance);
                }
            }
        }
        else if (menu == 5)
        {
            printf("doing_2\n");
            total = 0;
            for (int i = 0; i < cnt; i++)
            {
                total += acc[i].balance;
            }
            printf("Total=%.2lf\n", total);
            for (int i = 0; i < cnt; i++)
            {
                printf("%d %s %.2lf\n", acc[i].num, acc[i].name, acc[i].balance);
            }
        }
        else if (menu == 6)
        {
            break;
        }
    }
}