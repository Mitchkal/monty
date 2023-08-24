#include "monty.h"
/**
 * _pint - prints value at top of stack
 * @stack: the stack
 * @line_number: the line number
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		flag = 2;
	}
}

/**
 * pop - removes the top element of the stack
 * @stack: the stack
 * @line_number: the line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		flag = 2;
	}
	else
	{
		stack_t *current = *stack;
		*stack = current->next;
		free(current);
	}
}
/**
 * swap - swaps the top two elements in the stack
 * @stack: the stack
 * @line_number:  the line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		flag = 2;
	}
	else
	{
		int temp = (*stack)->n;

		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
	}
}
/**
 * nop - does nothing
 * @stack: the stack
 * @line_number: the line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * add - adds the top two elements of the stack, result stack is 1 elementshort
 * @stack: the stack; result stored in second top, top element removed
 * @line_number: the line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		flag = 2;
	}
	else
	{
		int temp = (*stack)->n;

		pop(stack, line_number);
		(*stack)->n += temp;
	}
}
