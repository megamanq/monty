#include "monty.h"

/**
 * main - Entry point for the Monty
 * ByteCode interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 * Return: 0 on success, 1 on failure.
 */

int main(int argc, char **argv)
{
	info.type = LIFO;
	if (argc != 2)
		handle_error(2);
	else
	{
	treat_monty(argv[1]);
	}
	return (EXIT_SUCCESS);
}
