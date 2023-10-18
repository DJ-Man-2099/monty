#include "monty.h"
stack_t *stack = NULL;
FILE *file = NULL;

/**
 * main - check code
 * @argc: num of args
 * @argv: args array
 *
 * checks code
 *
 * Return: 0 (Success)
 */
int main(int argc, char const *argv[])
{
	char *file_name = NULL, line[100];
	unsigned int count = 1;

	atexit(cleanup);
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_name = (char *)argv[1];

	file = fopen(file_name, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, 1000000000000000000, file) != NULL)
	{
		if (strlen(line) > 0 && !is_empty(line))
		{
			if (line[strlen(line) - 1] == '\n')
				line[strlen(line) - 1] = '\0';
			format_instruction(line, count);
			instruction->f(&stack, count);
			free(instruction);
			instruction = NULL;
			count++;
		}
	}

	return (0);
}
/**
 * free_stack - stack function
 * @stack: stack to free
 *
 * frees stack
 *
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *next = *stack;

	while ((*stack) != NULL)
	{
		next = (*stack)->next;
		free((*stack));
		(*stack) = NULL;
		(*stack) = next;
	}
}
/**
 * cleanup - clean at exit
 *
 * frees everything
 *
 * Return: void
 */
void cleanup(void)
{
	if (file != NULL)
		fclose(file);
	free_stack(&stack);
	if (instruction != NULL)
		free(instruction);
}
