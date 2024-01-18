#include "monty.h"

/**
 * push_usage_error - print push usage error message and exit
 */
void push_usage_error(void)
{
	print_error("usage: push integer");
	exit(EXIT_FAILURE);
}

/**
 * push_instruction - instruction function for the 'push' opcode
 * @stack: ...
 * @tokens: ...
 */
void push_instruction(stack_t **stack, char **tokens)
{
	if (tokens[1] == NULL || can_convert_to_int(tokens[1]) == 0)
		push_usage_error();

	push(stack, atoi(tokens[1]));
}

/**
 * can_convert_to_int - check if string can be converted to an int
 * @str: string to check
 * Return: 1 if string can be converted to an int, 0 if not
 */
int can_convert_to_int(char *str)
{
	if (*str == '+' || *str == '-')
		str++;

	while (*str)
	{
		if (!isdigit((unsigned char)*str))
			return (0);
		str++;
	}

	return (1);
}
