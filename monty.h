#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <ctype.h>

#define DELIMITER " \n\t\a"
#define LIFO 1
#define FIFO 0

/**
 * struct stack_s - Definition of a doubly linked list
 * node representing a stack (or queue)
 * @n: An integer value stored in the node
 * @prev: A pointer to the previous element in the stack (or queue)
 * @next: A pointer to the next element in the stack (or queue)
 *
 * Description: This structure defines a node in a doubly linked list,
 * designed for use in stack, queue, LIFO, and FIFO data structures
 * in the Holberton project.
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

void add_error(void);
void pop_error(void);
void handle_error(int code);
void swap_error(void);
void unknown_command(void);
void monty_usage(void);
void div_error(void);
void mod_error(void);
void push_use(void);
void _zero(void);
void pchar_error_2(void);
void sub_error(void);
void malloc_fail(void);
void file_perm(void);
void pint_error(void);
void pchar_error(void);
void mul_error(void);

int split(void);
int excute_monty(stack_t **stack);
int treat_monty(char *filename);

void pop_monty(stack_t **stack, unsigned int line_number);
void div_monty(stack_t **stack, unsigned int line_number);
void sub_monty(stack_t **stack, unsigned int line_number);
void pstr_monty(stack_t **stack, unsigned int line_number);
void _queue(stack_t **stack, unsigned int line_number);
void push_monty(stack_t **stack, unsigned int line_number);
void swap_monty(stack_t **stack, unsigned int line_number);
void rotl_monty(stack_t **stack, unsigned int line_number);
void _stack(stack_t **stack, unsigned int line_number);
void pchar_monty(stack_t **stack, unsigned int line_number);
void add_monty(stack_t **stack, unsigned int line_number);
void mod_monty(stack_t **stack, unsigned int line_number);
void rotr_monty(stack_t **stack, unsigned int line_number);
void nop_monty(stack_t **stack, unsigned int line_number);
void pint_monty(stack_t **stack, unsigned int line_number);
void mul_monty(stack_t **stack, unsigned int line_number);
void pall_monty(stack_t **stack, unsigned int line_number);

int _isdigit(char *str);
void add_node_fifo(stack_t **stack, stack_t *new_node);
void add_node_lifo(stack_t **stack, stack_t *new_node);
int dlistint_len(stack_t *stack);
int delete_dnodeint_at_index(stack_t **head, int index);
void free_list(stack_t *stack);
void *fill_an_array(void *a, int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void free_info(void);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/**
 * struct instruction_s - Definition of an instruction
 * for an opcode and its corresponding function
 * @opcode: The specific opcode identifier
 * @f: The function associated with the opcode
 *
 * Description: This structure defines an instruction
 * that associates an opcode with its corresponding function.
 * It is designed for use in stack, queue, LIFO, and FIFO data
 * structures in the Holberton project.
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct info_s - Definition of data extracted
 * from the Monty file
 * @cmd: The line extracted from the file
 * @arg: The argument to execute
 * @l_number: The line number in the file
 * @fp: The file descriptor
 * @fn: The file name
 * @type: The type, either FIFO or LIFO
 *
 * Description: This structure contains information about
 * the commands found in the Monty file, including the
 * extracted command line, argument, line number, file
 * descriptor, file name, and the type of data structure
 * (either FIFO or LIFO).
 */

typedef struct info_s
{
	char *cmd;
	char **arg;
	char *fn;
	int l_number;
	FILE *fp;
	int type;
} info_t;
extern info_t info;

/**
 * struct error - Error handling structure for
 * printing errors to stderr
 * @out: Error code
 * @error_type: Function to handle the error
 *
 * Description: This structure is used for error handling.
 * It contains an error code and a function to handle the
 * error and print it to the standard error
 * (stderr) stream.
 */

typedef struct error
{
	int out;
	void (*error_type)(void);
} error_t;

#endif
