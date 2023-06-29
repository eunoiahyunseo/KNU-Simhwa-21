#include <stdio.h>
#include <string.h>

int main()
{

    char stmt[30] = "Java is object oriented";
    char *charPtr_1 = "C_Best";
    char *charPtr = strncpy(stmt, charPtr_1, strlen(charPtr_1));
    printf("%s\n", charPtr);
}