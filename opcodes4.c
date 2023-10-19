#include "monty.h"
/**
 * rotr - monty opcode
 * @stack: stack to update
 * @line_number: number of instruction line
 *
 * executes the rotr
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack, *end,
			*new_start;

	(void)line_number;
	if (current != NULL && current->next != NULL)
	{
		new_start = current->next;
		end = get_end(*stack);
		current->prev = end;
		end->next = current;
		current->next = NULL;
		*stack = new_start;
	}
}
