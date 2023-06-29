#include <iostream>

#ifndef DEBUG
#define DEBUG == OK
#endif

#if defined DEBUG
#define DEBUGCODE(code_fragment) \
    {                            \
        code_fragment            \
    }
#else
#define DEBUGCODE(code_fragment)
#endif

using namespace std;
int main(void)
{

    // #ifdef DEBUG
    //     std::cout << "doing well DEBUG" << std::endl;

    // #endif

    // #ifdef COMPILE
    //     cout << "doing well COMPILE" << endl;
    // #endif

    DEBUGCODE(cout << "Selected" << endl;);
    return 0;
}