#include "monty.h"

/* Global variable */
char *op_arg;

/**
 * main - program entry point
 * @argc: length argv
 * @argv: command line arguments
 * Return: 0 success, 1 failure
 */

int main(int argc, char **argv)
{
	ssize_t read;
	size_t size = 0;
	FILE *fp;

	char *buffer = NULL, *opcode;
	stack_t *stack = NULL;

	int line = 1;

	/* check for arguments */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&buffer, &size, fp)) != -1)
	{
		/* split args */
		opcode = strtok(buffer, " \t\n");
		op_arg = strtok(NULL, " \t\n");

		if (handle_instruction(opcode, &stack, line) < 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
			exit(EXIT_FAILURE);
		}

		line++;

	}
	return (0);
}
