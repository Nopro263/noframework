#ifndef INCLUDE_STDLIB_CMD
#define INCLUDE_STDLIB_CMD

#include "../core/allocator.h"
#include "string.h"

return_t _cmd_input();
#define cmd_input() _cmd_input(__FUNCTION__)

#include "cmd.c"
#endif