#include "monty.h"

/**
 * pchar_monty - Prints the character
 * at the top of the stack.
 *
 * @stack: Pointer to the head of the stack.
 * @line_number: The line number where the function is called.
 *
 * Return: No return value (void).
 */

void pchar_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	(void)line_number;

	if (*stack == NULL)
		pchar_error();
	if (head->n >= 65 && head->n <= 90)
	{
		putchar(head->n);
		putchar('\n');
	}
	else if (head->n >= 97 && head->n <= 122)
	{
		putchar(head->n);
		putchar('\n');
	}
	else
	{
		pchar_error_2();
	}
}

/**
 * pchar_error_2 - Error when attempting to print
 * a character with a value out of the valid range.
 */

void pchar_error_2(void)
{
	fprintf(stderr, "L%d: can't pchar, value out of range\n", info.l_number);
	free_info();
	exit(EXIT_FAILURE);
}

/**
 * pstr_monty - Prints the string starting from
 * the top of the stack.
 *
 * @stack: Pointer to the head of the stack.
 * @line_number: The line number where the function is called.
 *
 * Return: No return value (void).
 */

void pstr_monty(stack_t **stack, unsigned int line_number)
{
	int i;
	stack_t *node;
	(void)line_number;

	node = *stack;
	if (*stack == NULL)
	{
		putchar('\n');
	}
	else
	{
		for (i = 0; node; i++)
		{
			if (node->n >= 65 && node->n <= 90)
				putchar(node->n);
			else if (node->n >= 97 && node->n <= 122)
				putchar(node->n);
			else if (node->n == 0)
				node = node->next;
			else
				break;
		node = node->next;
		}
		putchar('\n');
	}
}

/**
 * rotl_monty - Rotates the stack to move the
 * top element to the bottom.
 *
 * @stack: Pointer to the head of the stack.
 * @line_number: The line number where the function is called.
 *
 * Return: No return value (void).
 */

void rotl_monty(stack_t **stack, unsigned int line_number)
{
	int tmp;
	stack_t *copy;

	(void)line_number;

	if (stack && *stack)
	{
		tmp = (*stack)->n;

		for (copy = *stack; copy->next; copy = copy->next)
			copy->n = copy->next->n;
		copy->n = tmp;
	}
}
