#include "monty.h"

/**
 * _stack - Sets the format of the data to a stack (LIFO)
 * as the default behavior
 * @stack: Pointer to the head of the stack
 * @line_number: Line number
 * Return: Void
 */

void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	info.type = LIFO;
}

/**
 * _queue - Sets the format of the data to a queue (FIFO).
 * @stack: Pointer to the head of the queue
 * @line_number: Line number
 * Return: Void
 */

void _queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	info.type = FIFO;
}

/**
 * rotr_monty - Rotates the stack to move the
 * bottom element to the top.
 *
 * @stack: Pointer to the head of the stack.
 * @line_number: The line number where the function is called.
 *
 * Return: No return value (void).
 */

void rotr_monty(stack_t **stack, unsigned int line_number)
{
	int next, current;
	stack_t *copy;

	(void)line_number;

	if (stack && *stack)
	{
		copy = *stack;
		next = copy->n;

		while (copy->next)
		{
			current = next;
			next = copy->next->n;
			copy->next->n = current;
			copy = copy->next;
		}
		(*stack)->n = next;
	}
}

/**
 * dlistint_len - Returns the length of a doubly linked list.
 *
 * @stack: Head of the stack or queue.
 *
 * Return: The length of the list.
 */

int dlistint_len(stack_t *stack)
{
	int len = 0;
	int i = 0;

	for (i = 0; stack; i++)
	{
		len += 1;
		stack = stack->next;
	}
	return (len);
}

/**
 * delete_dnodeint_at_index - Deletes a node at a
 * given index in a doubly linked list.
 *
 * @head: Pointer to the list.
 * @index: Index of the node to be deleted.
 *
 * Return: 0 if successful, -1 if the deletion fails.
 */

int delete_dnodeint_at_index(stack_t **head, int index)
{
	stack_t *start;
	 int i;
	 int len = dlistint_len(*head);

	start = *head;
	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		start = start->next;
		free(*head);
		*head = start;
		if (start != NULL)
			start->prev = NULL;
		return (1);
	}
	for (i = 0; i <= index - 1; i++)
	{
		start = start->next;
		if (!start)
			return (-1);
	}
	if (len - 1 == index)
	{
		start->prev->next = NULL;
		free(start);
		return (1);
	}
	start->prev->next = start->next;
	start->next->prev = start->prev;
	free(start);
	return (1);
}
