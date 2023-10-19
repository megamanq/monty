#include "monty.h"

/**
 * nop_monty - Does nothing.
 *
 * @stack: Pointer to the head of the stack.
 * @line_number: The line number where the function is called.
 *
 * Return: No return value (void).
 */

void nop_monty(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * div_monty - Divides the second top
 * element by the top element.
 *
 * @stack: Pointer to the head of the stack.
 * @line_number: The line number where the function is called.
 */

void div_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	int check, sum = 0;
	stack_t *top1, *top2;
	(void)line_number;

	check = dlistint_len(head);
	if (check < 2)
		handle_error(11);
	top1 = head;
	top2 = head->next;
	if (top1->n == 0)
		handle_error(12);

	sum = top2->n / top1->n;
	(*stack)->n = sum;
	delete_dnodeint_at_index(stack, 1);
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

/**
 * mod_monty - Calculates the modulus of the
 * second top element and the top element.
 *
 * @stack: Pointer to the head of the stack.
 * @line_number: The line number where the function is called.
 */

void mod_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	int check, sum = 0;
	stack_t *top1, *top2;
	(void)line_number;

	check = dlistint_len(head);
	if (check < 2)
		handle_error(14);
	top1 = head;
	top2 = head->next;
	if (top1->n == 0)
		handle_error(12);
	sum = top2->n % top1->n;
	(*stack)->n = sum;
	delete_dnodeint_at_index(stack, 1);
}
