#ifndef _HEADER_
#define _HEADER_

#include <unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct globe - contains globar variables
 * @buffer: pointer to memory contains data
 * @op_arg: obtained from file .m
 * @fp: to read a file
 * @stack: stack implementation with doubly linked list
 *
 * Description: used like global variables
 */

struct globe
{
	char *buffer;
	char *op_arg;
	FILE *fp;
	stack_t *stack;
} globe;

struct globe glovars;



/* Function prototypes */

int is_digit(char *input);
int handle_instruction(char *opcode, stack_t **stack, unsigned int line);
void add_dnodeint(stack_t **head, const int n);
void push_to_stack(stack_t **stack, unsigned int line __attribute__((unused)));
void pall(stack_t **stack, unsigned int line __attribute__((unused)));
void free_stack(stack_t *head);
void before_exit(void);
void pint(stack_t **stack, unsigned int lin __attribute__((unused)));
void pop(stack_t **stack, unsigned int line __attribute__((unused)));
void swap(stack_t **stack, unsigned int line __attribute__((unused)));
void add(stack_t **stack, unsigned int line __attribute__((unused)));
int delete_node(stack_t **stack);

#endif
