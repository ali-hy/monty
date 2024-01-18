#include "monty.h"

/**
 * opcode_f - get the function f for opcode
 * @opcode: opcode for the instruction
 * Return: function that opcode
 */
void (*opcode_f(char *opcode))(stack_t **stack, char **tokens)
{
	if (strcmp(opcode, "push") == 0)
		return (push_instruction);
	else if (strcmp(opcode, "pall") == 0)
		return (pall_instruction);
	else if (strcmp(opcode, "pint") == 0)
		return (pint_instruction);
	else if (strcmp(opcode, "pop") == 0)
		return (pop_instruction);
	else if (strcmp(opcode, "swap") == 0)
		return (swap_instruction);
	else if (strcmp(opcode, "add") == 0)
		return (add_instruction);
	else if (strcmp(opcode, "nop") == 0)
		return (NULL);

	unknown_instruction_error(opcode);
	return (NULL);
}

/**
 * get_instruction - make instruction from input
 * @tokens: array of token strings
 * Return: instruction_t
 */
instruction_t *get_instruction(char **tokens)
{
	instruction_t *instruction = NULL;

	if (tokens == NULL)
		return (NULL);

	if (tokens[0] == NULL)
		return (NULL);

	instruction = malloc(sizeof(instruction_t));
	if (instruction == NULL)
		malloc_failed();

	instruction->opcode = tokens[0];
	instruction->f = opcode_f(instruction->opcode);

	return (instruction);
}
