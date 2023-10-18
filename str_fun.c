#include "monty.h"
/**
 * is_number - str check
 * @str: str to check
 *
 * Return: true if num,
 * false otherwise
 */
bool is_number(char *str)
{
	if (strlen(str) == 0)
		return (false);
	while (*str != '\0')
	{
		if (!isdigit(*str))
			return (false);
		str++;
	}

	return (true);
}
