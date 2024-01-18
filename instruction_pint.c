#include "monty.h"

/**
 * pint_instruction - function for the 'pint' opcode
 * @stack: ...
 * @tokens: ...
 */
void pint_instruction(stack_t **stack, char **tokens)
{
	if (*stack == NULL)
		print_error("can't pint, stack empty");
	printf("%d\n", (*stack)->n);
}
