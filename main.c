#include "monty.h"

/**
 * main - Monty entry point
 * @argc: num of args
 * @argv: array of args
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
int main(int argc, char *argv[])
{
	char **tokens = NULL;
	instruction_t *instruction = NULL;
	stack_t *stack = NULL, *next = NULL;

	if (argc != 2)
		usage_error();
	*input_global() = fopen(argv[1], "r");
	if (*input_global() == NULL)
		cant_open_file(argv[1]);

	while (1)
	{
		tokens = get_tokens();
		if (!tokens)
			break;

		instruction = get_instruction(tokens);
		if (instruction)
			instruction->f(&stack, tokens);

		free(instruction);
		free_string_array(tokens);
		tokens = NULL;
		instruction = NULL;
	}

	while (stack)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}

	fclose(*input_global());
	return (EXIT_SUCCESS);
}
