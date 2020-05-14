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
 * print_dlistint - print elements of double linked list
 * and return the number of nodes.
 *
 * @h: pointer to doubly linked list
 * Return: number of nodes
 */

void  print_dlistint(stack_t **h)
{
	stack_t *node = *h;

	if (*h != NULL)
	{
		while (node)
		{
			printf("%d\n", node->n);
			node = node->next;
		}

	}
}
