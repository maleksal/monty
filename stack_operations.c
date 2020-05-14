#include "monty.h"

/**
 * push_to_stack - push given input to stack
 * @stack: pointer to stack
 * @line: instruction line in case of error
 */

void push_to_stack(stack_t **stack, unsigned int line __attribute__((unused)))
{
	int arg;

	if (glovars.op_arg == NULL || is_digit(glovars.op_arg) < 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		before_exit();
		exit(EXIT_FAILURE);
	}

	arg = atoi(glovars.op_arg);
	add_dnodeint(stack, arg);
}

/**
  * pall - push given input to stack
  * @stack: pointer to stack
  * @line: instruction line in case of error
  */

void pall(stack_t **stack, unsigned int line __attribute__((unused)))
{
	stack_t *node = *stack;

	while (node)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}

/**
  * pint - print from top the  stack
  * @stack: pointer to stack
  * @line: instruction line in case of error
  */


void pint(stack_t **stack, unsigned int line __attribute__((unused)))
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		before_exit();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
  * pop - remove from top the stack
  * @stack: pointer to stack
  * @line: instruction line in case of error
  */


void pop(stack_t **stack, unsigned int line __attribute__((unused)))
{
	stack_t *pt = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		before_exit();
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free(pt);
}

/**
  * swap - swap two top nodes in stack
  * @head: pointer to stack
  * @line: instruction line in case of error
  */


void swap(stack_t **head, unsigned int line __attribute__((unused)))
{
	stack_t *node_1;
	stack_t *node_2;

	if ((*head) == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		before_exit();
		exit(EXIT_FAILURE);
	}

	node_1 = *head;
	node_2 = (*head)->next;
	node_1->next = node_2->next;
	node_1->prev = node_2;

	if (node_1->next)
		node_1->next->prev = node_1;

	node_2->next = node_1;
	node_2->prev = NULL;
	*head = node_2;
}
