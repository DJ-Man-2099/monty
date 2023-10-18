#include "monty.h"

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
	/**
	 * Steps:
	 * 1. Read File lines
	 *  1.1. Read Args (done)
	 *  1.2. Read File (done)
	 *  1.3. Read Lines Step by Step (done)
	 * 2. Format command
	 * 3. Execute command
	 */
	char *file_name = NULL, line[100];
	FILE *file = NULL;
	unsigned int count = 1;
	instruction_t *current;
	stack_t *stack = NULL;

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

	while (fgets(line, 100, file) != NULL)
	{
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';
		current = format_instruction(line, count);
		current->f(&stack, count);
		count++;
		free(current);
	}
	fclose(file);
	free_stack(&stack);
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
	stack_t *current = *stack, *next = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
