#include <stdio.h>
#include <string.h>

typedef struct contact_
{
    char name[100];
    char phoneNumber[100];
} contact;

int main(void)
{
    // 구조체 배열을 사용하여 주소록을 만들려고 한다.

    char inputFile[100] = {0};
    gets(inputFile);

    char findName[100] = {0};
    gets(findName);

    // 전화번호를 저장할 구조체 배열을 생성한다.
    contact contactList[100] = {0};

    FILE *fp_read;
    fp_read = fopen(inputFile, "r");

    int count = 0;
    int check_isPrint = -1;
    while (fscanf(fp_read, "%s\n%s", contactList[count].name, contactList[count].phoneNumber) != EOF)
    {
        if (!strcmp(contactList[count].name, findName))
        {
            printf("%s : %s", contactList[count].name, contactList[count].phoneNumber);
            check_isPrint = count;
        }
        count++;
    }
    if (check_isPrint == -1)
    {
        printf("cannot find");
    }

    return 0;
}