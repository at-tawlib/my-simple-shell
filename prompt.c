#include "shell.h"
#include "symtab/symtab.h"

/**
 * print_prompt1 - prints normal prompt
 * Return: void
 *
 * Update -  checks if there is a symbol table entry with the name PS!,
 * if there is we use that entry's value to print the first prompt string.
 * Otherwise, we use our default builtin value, which is $
 */
void print_prompt1(void)
{
	/* fprintf(stderr, "$ "); */
	struct symtab_entry_s *entry = get_symtab_entry("PS1");

	if (entry && entry->val)
	{
		fprintf(stderr, "%s", entry->val);
	}
	else
	{
		fprintf(stderr, "$ ");
	}
}

/**
 * print_prompt2 - prints continue prompt
 * Return: void
 */
void print_prompt2(void)
{
	/* fprintf(stderr, "> "); */
	struct symtab_entry_s *entry = get_symtab_entry("PS2");

	if (entry && entry->val)
	{
		fprintf(stderr, "%s", entry->val);
	}
	else
	{
		fprintf(stderr, "> ");
	}
}
