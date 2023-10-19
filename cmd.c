#include "monty.h"

/**
 * add_monty - Adds the top two
 * elements of the stack.
 *
 * @stack: Pointer to the head of the stack.
 * @line_number: The line number where the function is called.
 *
 * Return: No return value (void).
 */

void add_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	int check, sum = 0;
	stack_t *top1, *top2;
	(void)line_number;

	check = dlistint_len(head);
	if (check < 2)
		handle_error(9);
	top1 = head;
	top2 = head->next;
	sum = top1->n + top2->n;
	(*stack)->n = sum;
	delete_dnodeint_at_index(stack, 1);
}

/**
 * mul_error - Error when the stack is too short
 * to perform the 'mul' command.
 */

void mul_error(void)
{
	fprintf(stderr, "L%d: can't mul, stack too short\n", info.l_number);
	free_info();
}

/**
 * pall_monty - Display all values in the stack.
 * @stack: Pointer to the stack's head.
 * @line_number: Line number.
 * Return: No explicit return value.
 */

void pall_monty(stack_t **stack, unsigned int line_number)
{
	int i;
	stack_t *node;
	(void)line_number;

	node = *stack;
	for (i = 0; node; i++)
	{
		fprintf(stdout, "%d\n", node->n);
		node = node->next;
	}
}



/**
 * pop_monty - Remove the top element from the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number where the function is called.
 */

void pop_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *start = *stack;
	(void)line_number;

	if (*stack == NULL)
		handle_error(7);
	start = start->next;
	free(*stack);
	*stack = start;
	if (start != NULL)
		start->prev = NULL;
}

/**
 * swap_monty - Swaps the top two
 * elements of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: The line number where the function is called.
 *
 * Return: No return value (void).
 */

void swap_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	int check;
	stack_t *top, *under_top;
	(void)line_number;

	check = dlistint_len(head);
	if (check < 2)
		handle_error(8);
	top = head;
	under_top = head->next;
	top->next = under_top->next;
	top->prev = under_top;
	if (under_top->next)
		under_top->next->prev = top;
	under_top->next = top;
	under_top->prev = NULL;
	(*stack) = under_top;
}
