#include "monty.h"
/**
 * push - monty opcode
 * @stack: stack to update
 * @line_number: number of instruction line
 *
 * executes the push
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if ((*stack) != NULL)
		(*stack)->prev = global_current_stack;
	global_current_stack->next = (*stack);
	global_current_stack->prev = NULL;
	(*stack) = global_current_stack;
}
/**
 * pop - monty opcode
 * @stack: stack to update
 * @line_number: number of instruction line
 *
 * executes the pop
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *new_current = NULL;

	(void)line_number;
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next != NULL)
	{
		new_current = (*stack)->next;
		new_current->prev = NULL;
	}
	free((*stack));
	(*stack) = new_current;
}
/**
 * pall - monty opcode
 * @stack: stack to update
 * @line_number: number of instruction line
 *
 * executes the pall
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * pint - monty opcode
 * @stack: stack to update
 * @line_number: number of instruction line
 *
 * executes the pint
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", current->n);
}
/**
 * swap - monty opcode
 * @stack: stack to update
 * @line_number: number of instruction line
 *
 * executes the swap
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *top;

	(void)line_number;
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = (*stack)->next;
	temp = (*stack)->next->next;
	top->next = (*stack);
	top->prev = NULL;
	(*stack)->next = temp;
	(*stack)->prev = top;
	(*stack) = top;
}
