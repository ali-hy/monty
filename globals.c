#include "main.h"

/**
 * input_global - input file global
 * Return: pointer to input file global
 */
FILE **input_global(void)
{
	static FILE *value;

	return (&value);
}

/**
 * line_num_global - line number global
 * Return: pointer to line number variable
 */
int *line_num_global(void)
{
	static int line_num;

	return (&line_num);
}
