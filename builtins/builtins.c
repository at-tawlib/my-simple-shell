#include "../shell.h"

/**
 * builtin_s - array to contain our builtins
 */
struct builtin_s builtins[] = {
	{"dump", dump},
};

int builtins_count = sizeof(builtins) / sizeof(struct builtin_s);
