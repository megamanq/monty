#include "monty.h"

/**
 * _zero - Error when the top of the stack is 0
 * division or modulo operation not possible.
 */

void _zero(void)
{
	fprintf(stderr, "L%d: division by zero\n", info.l_number);
	free_info();
}

/**
 * push_monty - Add an element to the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number where the push operation occurs.
 * Return: No explicit return value.
 */

void push_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *n_node;
	(void)line_number;

	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
		handle_error(1);
	if (_isdigit(info.arg[1]) > 0)
		handle_error(5);
	n_node->n = atoi(info.arg[1]);
	if (info.type == LIFO)
	{
		add_node_lifo(stack, n_node);
	}
	else
		add_node_fifo(stack, n_node);
}

/**
 * mod_error - Error occurs when the stack is too
 * short to execute the 'mod' command.
 */

void mod_error(void)
{
	fprintf(stderr, "L%d: can't mod, stack too short\n", info.l_number);
	free_info();
}

/**
 * pint_monty - Print the value at the top of the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number where the function is called.
 */

void pint_monty(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack == NULL)
		handle_error(6);
	fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * sub_monty - Subtracts the top
 * element from the stack.
 *
 * @stack: Pointer to the head of the stack.
 * @line_number: The line number where the function is called.
 *
 * Return: No return value (void).
 */

void sub_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	int check, sum = 0;
	stack_t *top1, *top2;
	(void)line_number;

	check = dlistint_len(head);
	if (check < 2)
		handle_error(10);
	top1 = head;
	top2 = head->next;
	sum = top2->n - top1->n;
	(*stack)->n = sum;
	delete_dnodeint_at_index(stack, 1);
}
