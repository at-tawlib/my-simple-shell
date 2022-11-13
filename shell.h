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

#endif
