#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *money = "50,000";
    int intMoney = atoi(money);
    printf("intMoney >> %d\n", intMoney);
}