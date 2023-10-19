#include "monty.h"
/**
 * mul - monty opcode
 * @stack: stack to update
 * @line_number: number of instruction line
 *
 * executes the mul
 *
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *old_head = *stack;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n * (*stack)->next->n;
	(*stack) = (*stack)->next;
	(*stack)->n = sum;
	free(old_head);
}