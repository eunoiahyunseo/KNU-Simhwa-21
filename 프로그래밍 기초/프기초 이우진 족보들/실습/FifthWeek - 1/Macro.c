#include <stdio.h>
#define DEBUG

#if defined(DEBUG)
#define DebugCode(code_fragment) code_fragment
#else
#define DebugCode(code_fragment)
#endif

int main(void)
{
    DebugCode(printf("Hello Debug "););

    return 0;
}