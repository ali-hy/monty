#include "monty.h"

/**
 * get_tokens - get tokens
 * Return: array of token strings
 */
char **get_tokens(void)
{
	FILE *in_file = *input_global();
	int bytes_read = 0;
	size_t n = 0;
	char *line = NULL, **tokens = NULL;

	bytes_read = getline(&line, &n, in_file);
	(*line_num_global())++;

	if (bytes_read == -1)
	{
		free(line);
		return (NULL);
	}
	/* printf("read: %s", line); */

	tokens = split(line, " \n");
	free(line);
	return (tokens);
}

/**
 * split - separates string into an array of tokens
 * @str: string to separate
 * @delim: delimiters to separate tokens in str
 * Return: array of strings, where each string is a token
 */
char **split(char *str, char *delim)
{
	char *copy = NULL, *temp = NULL, **result = NULL, *token = NULL;
	int count, i;

	copy = malloc(strlen(str) + 1);
	if (copy == NULL)
		malloc_failed();

	strcpy(copy, str);

	count = 0;
	temp = strtok(copy, delim);
	while (temp != NULL)
	{
		count++;
		temp = strtok(NULL, delim);
	}

	result = malloc((count + 1) * sizeof(char *));
	if (result == NULL)
		malloc_failed();

	strcpy(copy, str);
	i = 0;
	token = strtok(copy, delim);
	while (token != NULL)
	{
		result[i] = malloc(strlen(token) + 1);
		if (result[i] == NULL)
			malloc_failed();
		strcpy(result[i], token);
		i++;
		token = strtok(NULL, delim);
	}
	result[i] = NULL;

	free(copy);
	if (result == NULL)
		printf("result is null lol\n");
	return (result);
}

/**
 * free_string_array - frees an array of strings
 * @arr: array of strings
 */
void free_string_array(char **arr)
{
	int i = 0;

	for (; arr[i] != NULL; i++)
		free(arr[i]);

	free(arr);
}
