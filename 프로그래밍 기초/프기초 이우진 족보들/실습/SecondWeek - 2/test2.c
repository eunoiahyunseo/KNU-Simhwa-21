#include <stdio.h>

int main(void)
{
    // char *pstr = "goodbye";
    // pstr[1] = 'a';
    // printf("%s", pstr);

    // char str[] = "hello";
    // str[1] = 'a';
    // printf("%s", str);

    // char str[100];
    // printf("%p\n", str);

    // printf("%p", str[0]);

    // char str[100] = {"abc"};
    // printf("%p\n", str);
    // printf("%p\n", str[0]);
    // printf("%p\n", str[1]);
    char c = 'a';
    char *c_ = "abc";
    c = 'b';
    *(c_ + 1) = "j";
    // printf("%c", c);

    printf("%p\n", c_);
    printf("%p\n", c_ + 1);
    printf("%p", &c_[0]);
}