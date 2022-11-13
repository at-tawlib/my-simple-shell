#ifndef SYMTAB_H
#define SYMTAB_H

#include "../node.h"

#define MAX_SYMTAB			256

/* the type of a symbol table entry's value */
enum symbol_type_e
{
	SYM_STR,	/* shell variable */
	SYM_FUNC,	/* shell function */
};

/* the symbol table entry structure */
struct symtab_entry_s
{
	char		*name;		/* name of shell variable represented by this entry */
	enum		symbol_type_e val_type;
	char		*val;		/* string value (for shell variables only) */
	unsigned	int flags;	/* diff properties assigned to variables and functions */
	struct		symtab_entry_s *next;	/* pointer to the next symbol table entry */
	struct		node_s *func_body;		/* shell fucntions, AST of the fuction body */
};

/* the symbol table structure */
struct symtab_s
{
	int		level;		/* 0 for global symbol table, 1 and above for local */
	struct	symtab_entry_s *first, *last;
};

/* values for the flags field of struct symtab_entry_s */
#define FLAG_EXPORT		(1 << 0) /* export entry to forked commands */

/* the symbol table stack structure */
struct symtab_stack_s
{
	int		symtab_count;	/* number of symbol tables currently on the stack */
	struct	symtab_s *symtab_list[MAX_SYMTAB]; /* array of pointers to the stack's symbol tables */
	struct	symtab_s *global_symtab, *local_symtab; /* pointers to global and local symbol tables */
};

struct symtab_s		*new_symtab(int level);
struct symtab_s		*symtab_stack_push(void);
struct symtab_s		*symtab_stack_pop(void);
int rem_from_symtab(struct symtab_entry_s *entry, struct symtab_s *symtab);
struct symtab_entry_s	*add_to_symtab(char *symbol);
struct symtab_entry_s	*do_lookup(char *str, struct symtab_s *symtable);
struct symtab_entry_s	*get_symtab_entry(char *str);
struct symtab_s			*get_local_symtab(void);
struct symtab_s			*get_global_symtab(void);
struct symtab_s			*get_symtab_stack(void);
void init_symtab(void);
void dump_local_symtab(void);
void free_symtab(struct symtab_s *symtab);
void symtab_entry_setval(struct symtab_entry_s *entry, char *val);

#endif
