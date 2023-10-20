#include "monty.h"
info_t info;
/**
 * split- Divide the input line into commands and arguments
 * Return: 0 if the splitting is successful, 1 on failure
 */

int split(void)
{
	char *token;
	size_t bufsize = 20, i = 0;

	info.arg = malloc(bufsize * sizeof(char *));
	if (info.arg == NULL)
		handle_error(1);
	token = strtok(info.cmd, DELIMITER);
	while (token)
	{
		info.arg[i++] = token;
		if (i >= bufsize)
		{
			info.arg = _realloc(info.arg, bufsize, bufsize * 2);
			if (info.arg == NULL)
			{
				handle_error(1);
			}
		}
		token = strtok(NULL, DELIMITER);
	}
	info.arg[i] = NULL;
	if (**info.arg == '#')
		return (-1);
	return (0);
}

/**
 * fill_an_array - Fill an array with a constant byte
 * @a: Pointer to the array
 * @el: The constant byte value to fill the array with
 * @len: The length of the array
 * Return: Pointer to the filled array
 */

void *fill_an_array(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}
