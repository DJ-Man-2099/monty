#include "monty.h"
/**
 * get_end - stack helper
 * @stack: stack
 *
 * returns the last element of stack
 *
 * Return: stack end pointer
 */
stack_t *get_end(stack_t *stack)
{
	stack_t *current = stack;

	while (current->next != NULL)
		current = current->next;
	return (current);
}
