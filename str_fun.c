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
	if (str[0] == '-')
		str++;
	while (*str != '\0')
	{
		if (!isdigit(*str))
			return (false);
		str++;
	}

	return (true);
}
/**
 * is_empty - str check
 * @str: str to check
 *
 * Return: true if empty,
 * false otherwise
 */
bool is_empty(char *str)
{
	if (strlen(str) == 0)
		return (false);
	while (*str != '\0')
	{
		if ((*str) != ' ' &&
			(*str) != '\t' &&
			(*str) != '\n')
			return (false);
		str++;
	}

	return (true);
}
