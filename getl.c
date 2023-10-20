#include "monty.h"

/**
 * getline - Read a line from a file stream and store it in a buffer.
 *
 * @lineptr: A pointer to a buffer to store the line.
 * @n: A pointer to the size of the buffer.
 * @stream: The file stream to read from.
 *
 * Return: The number of characters read, or -1 on failure.
 */

ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t pos = 0;
	int c;

	if (*lineptr == NULL) {
		*lineptr = (char *)malloc(128);
		if (*lineptr == NULL) {
			return -1;
		}
		*n = 128;
	}

	while ((c = getc(stream)) != EOF) {
		if (pos + 1 >= *n) {
			size_t new_size = *n * 2;
			char *new_lineptr = (char *)realloc(*lineptr, new_size);
			if (new_lineptr == NULL) {
				return -1;
			}
			*lineptr = new_lineptr;
			*n = new_size;
		}

		(*lineptr)[pos++] = c;

		if (c == '\n') {
			break;
		}
	}

	if (pos == 0) {
		return -1;
	}

	(*lineptr)[pos] = '\0';
	return pos;
}
