#include "monty.h"

/**
 * add_instruction - function for 'add' opcode
 * combines the top two elements into one that holds the sum of both
 * @stack: ...
 * @tokens: ...
 */
void add_instruction(stack_t **stack, char **tokens)
{
	int tmp;

	UNUSED(tokens);
	if (*stack == NULL || (*stack)->next == NULL)
		print_error("can't add, stack too short");

	tmp = (*stack)->n;
	pop_instruction(stack, NULL);
	(*stack)->n += tmp;
}

/**
 * sub_instruction - function for 'sub' opcode
 * combines the top two elements into one that holds the difference between
 * them
 * (second element - first element)
 * @stack: ...
 * @tokens: ...
 */
void sub_instruction(stack_t **stack, char **tokens)
{
	int tmp;

	UNUSED(tokens);
	if (*stack == NULL || (*stack)->next == NULL)
		print_error("can't sub, stack too short");

	tmp = (*stack)->n;
	pop_instruction(stack, NULL);
	(*stack)->n -= tmp;
}

/**
 * mul_instruction - function for 'mul' opcode
 * combines the top two elements into one that holds the product of both
 * @stack: ...
 * @tokens: ...
 */
void mul_instruction(stack_t **stack, char **tokens)
{
	int tmp;

	UNUSED(tokens);
	if (*stack == NULL || (*stack)->next == NULL)
		print_error("can't mul, stack too short");

	tmp = (*stack)->n;
	pop_instruction(stack, NULL);
	(*stack)->n *= tmp;
}

/**
 * div_instruction - function for 'div' opcode
 * combines the top two elements into one that holds their quotient
 * @stack: ...
 * @tokens: ...
 */
void div_instruction(stack_t **stack, char **tokens)
{
	int tmp;

	UNUSED(tokens);
	if (*stack == NULL || (*stack)->next == NULL)
		print_error("can't div, stack too short");

	if ((*stack)->n == 0)
		print_error("division by zero");
	tmp = (*stack)->n;
	pop_instruction(stack, NULL);
	(*stack)->n /= tmp;
}

/**
 * mod_instruction - function for 'mod' opcode
 * combines the top two elements into one that holds their quotient
 * @stack: ...
 * @tokens: ...
 */
void mod_instruction(stack_t **stack, char **tokens)
{
	int tmp;

	UNUSED(tokens);
	if (*stack == NULL || (*stack)->next == NULL)
		print_error("can't mod, stack too short");

	if ((*stack)->n == 0)
		print_error("division by zero");
	tmp = (*stack)->n;
	pop_instruction(stack, NULL);
	(*stack)->n %= tmp;
}
