#include "monty.h"

/**
  * add - swap two top nodes in stack
  * @stack: pointer to stack
  * @line: instruction line in case of error
  */


void add(stack_t **stack, unsigned int line __attribute__((unused)))
{
	int sum;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		before_exit();
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	printf("%d\n", sum);
}

