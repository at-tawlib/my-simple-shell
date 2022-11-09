#include "shell.h"
#include "source.h"
#include "parser.h"
#include "executor.h"

/**
 * main - entry point of app
 * @argc: number of arguments
 * @argv: arguments
 * Return: 0
 */
int main(int argc, char **argv)
{
	char *cmd;

	do {
		print_prompt1();

		cmd = read_cmd();
		if (!cmd)
		{
			exit(EXIT_SUCCESS);
		}

		/** if cmd is empty or end of line **/
		if (cmd[0] == '\0' || strcmp(cmd, "\n") == 0)
		{
			free(cmd);
			continue;
		}

		/** command is exit */
		if (strcmp(cmd, "exit\n") == 0)
		{
			free(cmd);
			break;
		}

		/** print out the command */
		/* printf("%s\n", cmd); */
		struct source_s src;

		src.buffer = cmd;
		src.buffsize = strlen(cmd);
		src.curpos = INIT_SRC_POS;
		parse_and_execute(&src);

		free(cmd);

	} while (1);

	return (0);
}


/**
 * parse_and_execute - parses and executes the command
 * @src: source or command to parse
 * Return: 0 or 1
 */
int parse_and_execute(struct source_s *src)
{
	skip_white_spaces(src);
	struct token_s *tok = tokenize(src);

	if (tok == &eof_token)
	{
		return (0);
	}

	while (tok && tok != &eof_token)
	{
		struct node_s *cmd = parse_simple_command(tok);

		if (!cmd)
		{
			break;
		}

		do_simple_command(cmd);
		free_node_tree(cmd);
		tok = tokenize(src);
	}
	return (1);
}
