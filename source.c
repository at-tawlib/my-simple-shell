#include "shell.h"
#include "source.h"

/**
 * unget_char - returns the last char retrieved from input
 * @src: input struct
 */
void unget_char(struct source_s *src)
{
	if (src->curpos < 0)
	{
		return;
	}
	src->curpos--;
}

/**
 * next_char - returns the next char of input and updates src
 * @src: source
 * Return: next char
 * Details - when we reach the last char, the function returns the
 * special char EOF (-1)
 */
char next_char(struct source_s *src)
{
	if (!src || !src->buffer)
	{
		errno  = ENODATA;
		return (ERRCHAR);
	}
	char c1 = 0;

	if (src->curpos == INIT_SRC_POS)
	{
		src->curpos = -1;
	}
	else
	{
		c1 = src->buffer[src->curpos];
	}
	if (++src->curpos == src->buffsize)
	{
		src->curpos = src->buffsize;
		return (EOF);
	}
	return (src->buffer[src->curpos]);
}


/**
 * peek_char - similar to next_char but does not update src pointer
 * @src: source
 * Return: next char
 */
char peek_char(struct source_s *src)
{
	if (!src || !src->buffer)
	{
		errno = ENODATA;
		return (ERRCHAR);
	}
	long pos = src->curpos;

	if (pos == INIT_SRC_POS)
	{
		pos++;
	}
	pos++;
	if (pos >= src->buffsize)
	{
		return (EOF);
	}
	return (src->buffer[pos]);
}

/**
 * skip_white_spaces - skips all the whitespace chars
 * @src: source
 */
void skip_white_spaces(struct source_s *src)
{
	char c;

	if (!src || !src->buffer)
	{
		return;
	}

	while (((c = peek_char(src)) != EOF) && (c == ' ' || c == '\t'))
	{
		next_char(src);
	}
}
