#ifndef NODE_H
#define NODE_H

/** defines the type of AST node */
enum node_type_e
{
	NODE_COMMAND,	/* simple command */
	NODE_VAR,		/* variable name (or simply, a word) */
};

/** types of values we can store in a node structure */
enum val_type_e
{
	VAL_SINT = 1,	/* signed int */
	VAL_UNIT,		/* unsigned int */
	VAL_SLLONG,		/* signed long long */
	VAL_ULLONG,		/* unsigned long long */
	VAL_FLOAT,		/* floating point */
	VAL_LDOUBLE,	/* long double */
	VAL_CHAR,		/* char */
	VAL_STR,		/* str (char pointer) */
};

/** the value we can store in a given node */
union symval_u
{
	long				sint;
	unsigned long		uint;
	long long			sllong;
	unsigned long long	ullong;
	double				sfloat;
	long double			ldouble;
	char				chr;
	char				*str;
};

/** 
 * this represent an AST node.
 * contains fields that tell us about the node's type,
 *	type of the node's value, the value itself
 */
struct node_s
{
	enum node_type_e type;		/* type of this node */
	enum val_type_e val_type;	/* type of this node's val field */
	union symval_u val;			/* value of this node */
	int children;				/* number of child nodes */
	struct node_s *first_child; /* first child node */
	struct node_s *next_sibling;
	struct node_s *prev_sibling;
};

struct node_s *new_node(enum node_type_e type);
void add_child_node(struct node_s *parent, struct node_s *child);
void free_node_tree(struct node_s *node);
void set_node_val_str(struct node_s *node, char *val);

#endif
