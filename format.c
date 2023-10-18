#include "monty.h"
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
	if (is_noargs(ptr))
		instruction->f = set_noargs(ptr);
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
 * is_noargs - opcode function
 * @opcode: str of opcode
 *
 * sets function of op code
 * for no args opcode
 *
 * Return: Function
 */
bool is_noargs(char *opcode)
{
	char *ops[] = {"pall", "pint", "pop",
				   "swap", NULL};
	size_t i;

	for (i = 0; ops[i] != NULL; i++)
		if (strcmp(opcode, ops[i]) == 0)
			return (true);

	return (false);
}
/**
 * set_noargs - opcode function
 * @opcode: str of opcode
 *
 * sets function of op code
 * for no args opcode
 *
 * Return: Function
 */
void (*set_noargs(char *opcode))(stack_t **stack, unsigned int line_number)
{
	if (strcmp(opcode, "pall") == 0)
		return (pall);
	else if (strcmp(opcode, "pint") == 0)
		return (pint);
	else if (strcmp(opcode, "swap") == 0)
		return (swap);
	else
		return (pop);
}
