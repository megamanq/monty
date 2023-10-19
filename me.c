#include "monty.h"

/**
 * free_info - Free allocated data
 */

void free_info(void)
{
	free(info.cmd);
	info.cmd = NULL;
	free(info.arg);
	info.arg = NULL;
	fclose(info.fp);
}

/**
 * _realloc - Reallocate memory block using malloc and free
 * @ptr: Pointer to the memory block
 * @old_size: Previous size of the memory block
 * @new_size: New size of the memory block
 * Return: Void pointer to the reallocated memory
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		fill_an_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, old_size);
		free(ptr);
	}
	return (result);
}

/**
 * free_list - Free memory associated with
 * a stack or queue
 * @stack: The stack or queue data structure
 * to be freed
 */

void free_list(stack_t *stack)
{
	stack_t *node;

	while (stack)
	{
		node = stack;
		stack = stack->next;
		free(node);
	}
}

/**
 * treat_monty - Process the Monty file
 * @filename: The filename provided as an argument
 * Return: Data extracted from the Monty file
 */

int treat_monty(char *filename)
{
	ssize_t n_r = 1;
	size_t len = 0;
	stack_t *stack = NULL;
	info_t info;

	info.fn = filename;
	info.fp = fopen(info.fn, "r");
	if (info.fp == NULL)
		handle_error(3);
	while ((n_r = getline(&info.cmd, &len, info.fp)) > 0)
	{
		if (*info.cmd == '\n')
			continue;
		info.l_number++;
		free(info.arg);
		if (split() < 0)
			continue;
		if (info.arg == NULL)
			continue;
		excute_monty(&stack);
	}
	free_info();
	free_list(stack);
	return (0);
}
