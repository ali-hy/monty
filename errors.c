#include "monty.h"

/**
 * print_error - prints an error
 * @msg: error message to print
 */
void print_error(char *msg)
{
	fprintf(stderr, "L%d: %s\n", *line_num_global(), msg);
}

/**
 * unknown_instruction_error - print unknown instruction error and exit
 * @opcode: opcode for this unknown instruction
 */
void unknown_instruction_error(char *opcode)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", *line_num_global(), opcode);
	exit(EXIT_FAILURE);
}

/**
 * usage_error - ...
 */
void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * cant_open_file - ...
 * @f_name: file name
 */
void cant_open_file(char *f_name)
{
	fprintf(stderr, "Error: Can't open file %s\n", f_name);
	exit(EXIT_FAILURE);
}

/**
 * malloc_failed - ...
 */
void malloc_failed(void)
{
	print_error("Error: malloc failed");
	exit(EXIT_FAILURE);
}
