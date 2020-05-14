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

	/* delete_node */
	delete_node(stack);
	delete_node(stack);
	/* add sum at top of stack */
	add_dnodeint(stack, sum);
}

/**
  * sub - swap two top nodes in stack
  * @stack: pointer to stack
  * @line: instruction line in case of error
  */


void sub(stack_t **stack, unsigned int line __attribute__((unused)))
{
	int sub;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		before_exit();
		exit(EXIT_FAILURE);
	}

	sub = (*stack)->next->n - (*stack)->n;

	/* delete_node */
	delete_node(stack);
	delete_node(stack);
	/* add sum at top of stack */
	add_dnodeint(stack, sub);
}

