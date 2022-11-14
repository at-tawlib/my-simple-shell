#include "../shell.h"
#include "../symtab/symtab.h"

/**
 * dump - implements the dum builtin utility which prints the
 * contents of the local symbol table
 * @argc: args count
 * @argv: arguments
 * Return: 0
 */
int dump(int argc, char **argv)
{
	dump_local_symtab();
	return (0);
}
