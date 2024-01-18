#ifndef MAIN_H
#define MAIN_H

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/file.h>
#include <limits.h>
#include <ctype.h>

#define UNUSED(x) (void)(x)

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
	void (*f)(stack_t **stack, char **tokens);
} instruction_t;

/**
 * struct error_s - struct representing an error
 * @line_num: line number
 * @message: error message
 *
 * Description: hold error details
 */
typedef struct error_s
{
	int line_num;
	char *message;
} error_t;

/* UTILS */
int can_convert_to_int(char *str);

/* GLOBAL */
error_t *error_global(void);
FILE **input_global(void);
int *line_num_global(void);

/* ERRORS */
void print_error(char *msg);
void usage_error(void);
void cant_open_file(char *);
void malloc_failed(void);
void unknown_instruction_error(char *opcode);

/* TOKENS */
char **get_tokens(void);
char **split(char *str, char *delim);
void free_string_array(char **arr);

/* STACK */
stack_t *stack_node(int value, stack_t *prev, stack_t *next);
void push(stack_t **, int n);
void pop(stack_t **);
int pall(stack_t **);
int pint(stack_t **);
int add(stack_t **);

/* INSTRUCTIONS */
instruction_t *get_instruction();
int execute_instruction(instruction_t *);

void push_instruction(stack_t **stack, char **tokens);
void push_usage_error(void);

void pall_instruction(stack_t **stack, char **tokens);

#endif /* MAIN_H */
