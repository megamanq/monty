#include "monty.h"

/**
 * add_error - Handle errors when using the
 * add command and the stack is too short
 */

void add_error(void)
{
	fprintf(stderr, "L%d: can't add, stack too short\n", info.l_number);
	free_info();
}

/**
 * malloc_fail - Handle errors in case of malloc failure
 */

void malloc_fail(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_info();
}

/**
 * pint_error - Handle errors when using the pint command on an empty stack
 */

void pint_error(void)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", info.l_number);
	free_info();
}

/**
 * unknown_command - Handle errors for unknown commands
 */

void unknown_command(void)
{
	fprintf(stderr, "L%d: unknown instruction %s\n",
			info.l_number, info.arg[0]);
		free_info();
}
