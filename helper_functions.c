#include "monty.h"


/**
 * is_digit - check if given input is integer
 * @input: string
 * Return: 0 if integer, -1 if contains any non integer ascii code
 */

int is_digit(char *input)
{
	int i = 0;

	if (input[0] == '-')
		i = 1;

	for ( ; input[i] != '\0'; i++)
	{
		if (input[i] < 48 || input[i] > 57)
			return (-1);
	}
	return (0);
}

/**
 * before_exit - frees necessary data before exit
 */

void before_exit(void)
{
	fclose(glovars.fp);
	free(glovars.buffer);
	free_stack(glovars.stack);
}
