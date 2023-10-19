#include "monty.h"

/**
 * push_use - Handle errors related to the usage of the push command
 */

void push_use(void)
{
	fprintf(stderr, "L%d: usage: push integer\n", info.l_number);
	free_info();
}

/**
 * file_perm - Handle errors related to permissions or
 * file opening failure
 */

void file_perm(void)
{
	fprintf(stderr, "Error: Can't open file %s\n", info.fn);
}

/**
 * pop_error - Handle errors when the stack is empty
 */

void pop_error(void)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", info.l_number);
	free_info();
}

/**
 * monty_usage - Handle errors related to
 * interpreter usage
 */

void monty_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
}

