#ifndef __MONTY_H__
#define __MONTY_H__

#define  _POSIX_C_SOURCE 200809L
#define UNUSED(x) (void)(x)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct data_s - datas
 * @line: line number
 * @stack: stack pointer;
 * @len: stack length
 * @input: line instructions
 * @stream: input stream
 * @status: return status
 * @file: file name
 * @arg: the opc arg
 *
 * Description: all important datas are here
 */

typedef struct data_s
{
	int line;
	stack_t *stack;
	int len;
	char *input;
	char *file;
	FILE *stream;
	char *arg;
} data_t;

data_t datas;

/* error_handler.c */
void error_handler(int code);
char *error_malloc();

/* exec.c */
int check_stop(char c);
int exec_loop();

/* mem_utils.c */
char *_memcpy(char *dest, const char *src, unsigned int n);

/* char_utils.c */
int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char *_strtok(char str[], const char *delim);

/* char_utils1.c */
int _charchk(char str[], const char *delim);
int _strcmp(char *s1, char *s2);

/* init.c */
void _init_stream(char **av);
void _free_datas();

/* op_handler.c */
void (*get_op_function(char *opc))(stack_t **stack, unsigned int line_number);

/* op0.c */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);

/* op1.c */
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);

/* utils.c */
stack_t *add_dnodeint(stack_t **head, const int n);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
void free_dlistint(stack_t *head);

#endif
