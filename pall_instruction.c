#include "monty.h"

/**
 * pall_instruction - function for opcode pall
 * prints entire stack
 * @stack: ...
 * @tokens: ...
 */
void pall_instruction(stack_t **stack, char **tokens)
{
	stack_t *curr = *stack;

	UNUSED(tokens);

	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
