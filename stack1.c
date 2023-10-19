#include "monty.h"

/**
 * add_node_lifo - Adds a node in a Last-In, First-Out (LIFO) manner
 * @stack: Pointer to the head of the stack
 * @n_node: The node to add
 */

void add_node_lifo(stack_t **stack, stack_t *n_node)
{
	n_node->prev = NULL;
	n_node->next = *stack;
	if (*stack)
		(*stack)->prev = n_node;
	*stack = n_node;
}

/**
 * add_node_fifo - Adds a node in a First-In, First-Out (FIFO) manner
 * @stack: Pointer to the head of the stack
 * @n_node: The node to add
 */

void add_node_fifo(stack_t **stack, stack_t *n_node)
{
	stack_t *tmp = *stack;

	n_node->next = NULL;
	if (!*stack)
	{
		n_node->prev = NULL;
		*stack = n_node;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = n_node;
		n_node->prev = tmp;
	}
}
