#include "monty.h"

/**
 * add_instruction - function for 'add' opcode
 * combins the top two elements into one that holds the sum of both
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
