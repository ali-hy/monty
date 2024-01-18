#include "monty.h"

/**
 * pall_instruction - function for 'pall' opcode
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

/**
 * pint_instruction - function for the 'pint' opcode
 * prints element at the top of the stack
 * @stack: ...
 * @tokens: ...
 */
void pint_instruction(stack_t **stack, char **tokens)
{
	UNUSED(tokens);
	if (*stack == NULL)
		print_error("can't pint, stack empty");
	printf("%d\n", (*stack)->n);
}

/**
 * pop_instruction - function for the 'pop' opcode
 * removes top element of stack
 * @stack: ...
 * @tokens: ...
 */
void pop_instruction(stack_t **stack, char **tokens)
{
	stack_t *temp = *stack;

	UNUSED(tokens);
	if (*stack == NULL)
		print_error("can't pop an empty stack");

	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(temp);
}
