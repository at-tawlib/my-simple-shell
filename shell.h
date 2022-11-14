#ifndef _SHELL_H
#define _SHELL_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "source.h"

void print_prompt1(void);
void print_prompt2(void);
char *read_cmd(void);
int parse_and_execute(struct source_s *src);
void initsh(void);

/* shell builtin utilities */
int dump(int argc, char **argv);

/* shell builtin utilities */
struct builtin_s
{
	char *name;		/* utility name */
	int (*func) (int argc, char **argv);  /* function to call to execute the utility */
};

/* the list of builtin utilities, use to store info about builtin utilities */
extern struct builtin_s builtins[];

/* and their count */
extern int builtins_count;

#endif
