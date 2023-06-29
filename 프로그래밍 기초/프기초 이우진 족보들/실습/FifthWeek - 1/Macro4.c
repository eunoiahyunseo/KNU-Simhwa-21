#define SYSTEM MAC

#if SYSTEM == WINDOWS
#include <stdio.h>
#elif System == MAX
#include "vax.h"
#elif SYSTEM == UNIX
#include "unix.h"
#else
#include "etc.h"
#endif
