#include "monty.h"
/**
 * sub - subtracts top element from second top
 * @stack: the stack
 * @line_number: the line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		flag = 2;
	}
	else
	{
		int temp = (*stack)->n;

		pop(stack, line_number);
		(*stack)->n -= temp;
	}
}

/**
 * _div - divides second top element by top
 * @stack: the stack
 * @line_number: the line number
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		flag = 2;
	}
	else
	{
		int temp = (*stack)->n;
		int tamp = (*stack)->next->n;

		if (temp == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			flag = 2;
		}
		else
		{
			pop(stack, line_number);
			(*stack)->n = tamp / temp;
		}
	}
}
/**
 * _mod - finds modulus second top element by top
 * @stack: the stack
 * @line_number: the line number
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		flag = 2;
	}
	else
	{
		int temp = (*stack)->n;
		int tamp = (*stack)->next->n;

		if (temp == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			flag = 2;
		}
		else
		{
			pop(stack, line_number);
			(*stack)->n = tamp % temp;
		}
	}
}

/**
 * _mul - multiplies second top element by top
 * @stack: the stack
 * @line_number: the line number
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		flag = 2;
	}
	else
	{
		int temp = (*stack)->n;
		int tamp = (*stack)->next->n;

		pop(stack, line_number);
		(*stack)->n = tamp * temp;
	}
}
/**
 * comment - handles comments
 * @stack: the stack
 * @line_number: the line number
 */

void comment(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
