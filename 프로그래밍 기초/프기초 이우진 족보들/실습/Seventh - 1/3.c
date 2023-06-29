#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>

int main(void)
{

    char ch;
    printf("\n문자를 누를 때마다 두번 출력 >> \n");
    while ((ch = getch() != 'q'))
    {
        putchar(ch);
    }
}