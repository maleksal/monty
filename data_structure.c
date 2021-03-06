#include "monty.h"

/**
 * add_dnodeint - add a node to the begginning of a dlistint_t list
 * @head: pointer to doubly linked list
 * @n: integer datatype of the new node
 * Return: addr of new node or NULL if it failed
 */

void add_dnodeint(stack_t **head, const int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed)");
		before_exit();
		exit(EXIT_FAILURE);
	}

	node->n = n;
	node->next = NULL;
	node->prev = NULL;

	if (*head != NULL)
	{
		(*head)->prev = node;
		node->next = *head;
	}

	*head = node;
}

/**
 * free_stack - frees a doubly linked list
 * @head: pointer to doubly linked list
 */

void free_stack(stack_t *head)
{
	stack_t *node = head;

	while (head)
	{
		node = head->next;
		free(head);
		head = node;
	}
}

/**
 * delete_node - delete fisrt node from linked list
 * @stack: head of linked list
 * Return: 0 if sucess, 1 if fail
 */

int delete_node(stack_t **stack)
{
	stack_t *pt = *stack;

	if (stack == NULL || *stack == NULL)
		return (-1);
	*stack = (*stack)->next;
	free(pt);
	return (1);
}
