#include "monty.h"
/**
 * stack_node - stack_t constructor
 * @value: value of stack_node
 * @prev: prev node
 * @next: next node
 * Return: stack_node
 */
stack_t *stack_node(int value, stack_t *prev, stack_t *next)
{
	stack_t *res = malloc(sizeof(stack_t));

	if (res == NULL)
		return (NULL);

	res->n = value;
	res->prev = prev;
	res->next = next;

	return (res);
}

/**
 * push - push a value to the stack
 * @stack: top stack node
 * @value: value of node to push
 * Return: new
 */
void push(stack_t **stack, int value)
{
	stack_t *new_node = stack_node(value, NULL, *stack);

	if ((*stack))
		(*stack)->prev = new_node;
	*stack = new_node;
}
