#include "monty.h"

/**
 * swap_error - Handle errors when the stack length is less than 2
 */

void swap_error(void)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", info.l_number);
	free_info();
}

/**
 * sub_error - Handle errors when using the
 * sub command and the stack is too short
 */

void sub_error(void)
{
	fprintf(stderr, "L%d: can't sub, stack too short\n", info.l_number);
	free_info();
}

/**
 * div_error - Handle errors when the stack is
 * too short for the div command
 */

void div_error(void)
{
	fprintf(stderr, "L%d: can't div, stack too short\n", info.l_number);
	free_info();
}

/**
 * handle_error - Print error messages and exit
 * @code: The exit code to indicate the error
 */

void handle_error(int code)
{
	error_t er[] = {
		{1, malloc_fail},
		{2, monty_usage},
		{3, file_perm},
		{4, unknown_command},
		{5, push_use},
		{6, pint_error},
		{7, pop_error},
		{8, swap_error},
		{9, add_error},
		{10, sub_error},
		{11, div_error},
		{12, _zero},
		{13, mul_error},
		{14, mod_error},
		{0, NULL}
	};
	int i = 0;

	while ((er + i)->out)
	{
		if ((er + i)->out == code)
		{
			(er + i)->error_type();
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
