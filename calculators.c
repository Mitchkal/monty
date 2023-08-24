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
