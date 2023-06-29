#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printPhoneNumber(char *phoneNumber);

int main(void)
{
    typedef struct Customer_
    {
        char name[100];
        char phoneNumber[100];
        char generalNumber[100];
    } Customer;

    int value;
    scanf("%d", &value);
    Customer customerArray[value];

    for (int i = 0; i < value; i++)
    {
        scanf("%s %s %s", customerArray[i].name, customerArray[i].phoneNumber, customerArray[i].generalNumber);
    }

    while (1)
    {
        char nameBuffer[100];
        scanf("%s", nameBuffer);

        if (strcmp(nameBuffer, "exit") == 0)
        {
            break;
        }
        else
        {
            int searchCustomerCount = 0;
            for (int i = 0; i < value; i++)
            {

                if (strcmp(nameBuffer, customerArray[i].name) == 0)
                {
                    // 먄약 전화번호가 있다면
                    if (strcmp(customerArray[i].phoneNumber, "NA") != 0)
                    {
                        printf("%s\n", customerArray[i].phoneNumber);
                        searchCustomerCount++;
                    }
                    else
                    { // 전화번호가 없다면
                        printf("%s\n", customerArray[i].generalNumber);
                        searchCustomerCount++;
                    }
                }
            }
            if (searchCustomerCount == 0)
            {
                printf("Search Fail\n");
            }
        }
    }

    return 0;
}
