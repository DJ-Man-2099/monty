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
	stack_t *current = *stack, *end;

	(void)line_number;
	if (current != NULL && current->next != NULL)
	{
		end = get_end(*stack);
		end->prev->next = NULL;
		end->prev = NULL;
		end->next = current;
		*stack = end;
	}
}
