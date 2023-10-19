#include "monty.h"

/**
 * mul_monty - Multiplies the second top
 * element by the top element.
 *
 * @stack: Pointer to the head of the stack.
 * @line_number: The line number where the function is called.
 */

void mul_monty(stack_t **stack, unsigned int line_number)
{
		stack_t *head = *stack;
	int check, sum = 0;
	stack_t *top1, *top2;
	(void)line_number;

	check = dlistint_len(head);
	if (check < 2)
		handle_error(13);
	top1 = head;
	top2 = head->next;
	sum = top2->n * top1->n;
	(*stack)->n = sum;
	delete_dnodeint_at_index(stack, 1);
}

/**
 * pchar_error - Error when attempting to print
 * a character with an empty stack.
 */

void pchar_error(void)
{
	fprintf(stderr, "L%d: can't pchar, stack empty\n", info.l_number);
	free_info();
	exit(EXIT_FAILURE);
}
