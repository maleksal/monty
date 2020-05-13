#include "header.h"


/**
 * is_digit - check if given input is integer
 * @input: string
 * Return: 0 if integer, -1 if contains any non integer ascii code
 */

int is_digit(char *input)
{
	int i;

	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] < 48 || input[i] > 57)
			return (-1);
	}
	return (0);
}
