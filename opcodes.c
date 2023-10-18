#include "monty.h"
#define DELIM " \t"
stack_t *global_current_stack;
instruction_t *instruction;
/**
 * format_instruction - monty code reader
 * @line: line to extract function
 * @line_number: number of line of instruction
 *
 * reads line, and returns the instruction
 *
 * Return: instruction struct
 */
instruction_t *format_instruction(char *line, unsigned int line_number)
{
	char *ptr;

	instruction = malloc(sizeof(instruction_t));
	if (instruction == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	memset(instruction, 0, sizeof(instruction_t));
	ptr = strtok(line, DELIM);
	instruction->opcode = ptr;
	if (strcmp(ptr, "pall") == 0)
		instruction->f = pall;
	else if (strcmp(ptr, "pint") == 0)
		instruction->f = pint;
	else if (strcmp(ptr, "push") == 0)
	{
		instruction->f = push;
		ptr = strtok(NULL, DELIM);
		if (ptr == NULL || !is_number(ptr))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		global_current_stack = malloc(sizeof(stack_t));
		if (global_current_stack == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		global_current_stack = memset(global_current_stack, 0, sizeof(stack_t));
		global_current_stack->n = atoi(ptr);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, ptr);
		exit(EXIT_FAILURE);
	}

	return (instruction);
}
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
	{
		(*stack)->prev = global_current_stack;
		global_current_stack->next = (*stack);
	}
	(*stack) = global_current_stack;
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
