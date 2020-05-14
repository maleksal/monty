#include "monty.h"

/**
 * handle_instruction - check if instruction exists then makes
 * a call to corresponding function.
 *
 * @opcode: instruction
 * @stack: pointer to stack
 * @line: line where the instruction, in case of error
 * Return: 0 sucess, -1 fail
 */

int handle_instruction(char *opcode, stack_t **stack, unsigned int line)
{
	instruction_t opcodes[] = {
	{"push", push_to_stack},
	{"pall", pall},
	{NULL, NULL}};

	int i;


	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (opcode != NULL && strcmp(opcodes[i].opcode, opcode) == 0)
		{
			opcodes[i].f(stack, line);
			return (0);
		}
	}
	return (-1);
}
