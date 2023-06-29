#include <stdio.h>
#include <stdlib.h>
#define type(x) _Generic((x),                                      \
                         _Bool                                     \
                         : "_Bool", unsigned char                  \
                         : "unsigned char",                        \
                           char                                    \
                         : "char", signed char                     \
                         : "signed char",                          \
                           short int                               \
                         : "short int", unsigned short int         \
                         : "unsigned short int",                   \
                           int                                     \
                         : "int", unsigned int                     \
                         : "unsigned int",                         \
                           long int                                \
                         : "long int", unsigned long int           \
                         : "unsigned long int",                    \
                           long long int                           \
                         : "long long int", unsigned long long int \
                         : "unsigned long long int",               \
                           float                                   \
                         : "float", double                         \
                         : "double",                               \
                           long double                             \
                         : "long double", char *                   \
                         : "char *",                               \
                           void *                                  \
                         : "void *", int *                         \
                         : "int *",                                \
                           default                                 \
                         : "unknown")

int main(void)
{

    char str[30];
    int i;

    scanf("%s", str);
    sscanf(str, "%d", &i);
    printf("Number from : '%s' \n", str);
    printf("number : %d \n", i);
    printf("%s\n%s\n", type(str), type(i));

    sprintf(str, "%d", 10);
    printf("%s\n", str);
    printf("%s\n", type(str));

    return 0;
}