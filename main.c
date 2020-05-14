#include "monty.h"

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
	char *opcode;
	int line = 1;

	glovars.stack = NULL;
	/* check for arguments */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	glovars.fp = fopen(argv[1], "r");
	if (glovars.fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&glovars.buffer, &size, glovars.fp)) != -1)
	{
		/* split args */
		opcode = strtok(glovars.buffer, " \t\n");
		glovars.op_arg = strtok(NULL, " \t\n");

		if (handle_instruction(opcode, &glovars.stack, line) < 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
			before_exit();
			exit(EXIT_FAILURE);
		}
		line++;
	}

	before_exit();
	return (0);
}
