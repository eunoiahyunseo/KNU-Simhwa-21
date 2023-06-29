#include <stdio.h>

int main(void)
{

    char ch;
    printf("문자를 계속 입력하고 Enter를 누르면 >> \n");
    while ((ch = getchar()) != 'q')
    {
        putchar(ch);
    }
}