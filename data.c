#include "monty.h"
info_t info;
/**
 * _isdigit - Check if a character is a
 * digit from 0 to 9
 * @str: The character to be checked
 * Return: 1 if it is a digit, 0 otherwise
 */

int _isdigit(char *str)
{
	int i = 0;

	if (str == NULL)
		return (1);
	while (str[i])
	{
		if (isdigit(*str) == 0)
			return (1);
		i++;
	}
	return (0);
}

/**
 * _memcpy - Copy bytes from source to destination
 * @dest: Destination pointer
 * @src: Source pointer
 * @n: Number of bytes to copy
 * Return: Void pointer
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * execute_monty - Verify a Monty command and
 * perform the execution
 * @stack: The stack or queue data structure
 * Return: 0 for a valid command, 1 if the command
 * is not recognized
 */

int excute_monty(stack_t **stack)
{
	instruction_t command[] = {
		{"push", push_monty},
		{"pall", pall_monty},
		{"pint", pint_monty},
		{"pop", pop_monty},
		{"swap", swap_monty},
		{"add", add_monty},
		{"nop", nop_monty},
		{"sub", sub_monty},
		{"div", div_monty},
		{"mul", mul_monty},
		{"mod", mod_monty},
		{"#", nop_monty},
		{"pchar", pchar_monty},
		{"pstr", pstr_monty},
		{"rotl", rotl_monty},
		{"rotr", rotr_monty},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};
	int i = 0;

	while ((command + i)->opcode)
	{
		if (strcmp((command + i)->opcode, *info.arg) == 0)
		{
			(command + i)->f(stack, info.l_number);
			return (0);
		}
		i++;
	}
	handle_error(4);
	return (1);
}
