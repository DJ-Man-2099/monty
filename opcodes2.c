#include "monty.h"
/**
 * add - monty opcode
 * @stack: stack to update
 * @line_number: number of instruction line
 *
 * executes the add
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *old_head = *stack;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	(*stack) = (*stack)->next;
	(*stack)->n = sum;
	free(old_head);
}
/**
 * sub - monty opcode
 * @stack: stack to update
 * @line_number: number of instruction line
 *
 * executes the sub
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *old_head = *stack;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = -(*stack)->n + (*stack)->next->n;
	(*stack) = (*stack)->next;
	(*stack)->n = sum;
	free(old_head);
}
/**
 * div - monty opcode
 * @stack: stack to update
 * @line_number: number of instruction line
 *
 * executes the div
 *
 * Return: void
 */
void div(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *old_head = *stack;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n / (*stack)->n;
	(*stack) = (*stack)->next;
	(*stack)->n = sum;
	free(old_head);
}
/**
 * nop - monty opcode
 * @stack: stack to update
 * @line_number: number of instruction line
 *
 * executes the nop
 *
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
