#include "monty.h"

/**
 * push_to_stack - push given input to stack
 * @stack: pointer to stack
 * @line: instruction line in case of error
 */

void push_to_stack(stack_t **stack, unsigned int line __attribute__((unused)))
{
	int arg;

	if (op_arg == NULL || is_digit(op_arg) < 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}

	arg = atoi(op_arg);
	add_dnodeint(stack, arg);
}

/**
  * pall - push given input to stack
  * @stack: pointer to stack
  * @line: instruction line in case of error
  */

void pall(stack_t **stack, unsigned int line __attribute__((unused)))
{
	 print_dlistint(stack);
}
