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
/**
 * mod - monty opcode
 * @stack: stack to update
 * @line_number: number of instruction line
 *
 * executes the mod
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *old_head = *stack;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n % (*stack)->n;
	(*stack) = (*stack)->next;
	(*stack)->n = sum;
	free(old_head);
}
/**
 * pchar - monty opcode
 * @stack: stack to update
 * @line_number: number of instruction line
 *
 * executes the pchar
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (current->n > 127 || current->n <= 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", current->n);
}
