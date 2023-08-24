#include "monty.h"
/**
 * push_op - stores values to stack
 * @stack: the stack
 * @line_number: the line number
 * @push_argument: the argument to push
 */

void push_op(stack_t **stack, unsigned int line_number, int push_argument)
{
	stack_t *new_node = NULL;

	(void)line_number;

	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}
	new_node->n = push_argument;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * print_operation- prints the stack
 * @stack: the stack
 * @line_number: the line number
 */
void print_operation(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (stack != NULL)
	{
		stack_t *current = *stack;

		while (current != NULL)
		{
			printf("%d\n", current->n);
			current = current->next;
		}
	}
	else
		return;
	/*printf("printing contents on line number: %u\n", line_number);*/
}

/**
 * free_stack - frees the stack
 * @stack: the stack
 */

void free_stack(stack_t *stack)
{
	stack_t *current = stack;

	while (current != NULL)
	{
		stack_t *temp = current;

		current = current->next;
		free(temp);
	}
}
