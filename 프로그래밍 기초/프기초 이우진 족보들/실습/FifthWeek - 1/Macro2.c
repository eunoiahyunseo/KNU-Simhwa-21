#define DEBUG
#include <stdio.h>

int main(void)
{

#if defined(DEBUG)
    printf("Hello DEBUG");
#endif

    return 0;
}