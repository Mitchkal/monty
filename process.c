#include "monty.h"
/**
 * process_command - processes the command
 * @opcode: the read opcode instruction
 * @line_number: the line number
 * @flag: the exit flag
 * @stack: the stack
 */
void process_command(stack_t **stack, char *opcode,
		unsigned int line_number, int *flag)
{
	int i = 0;
	/*char opcode[256];*/
	instruction_t instructions[] = {
		{"pop", pop},
		{"pall", print_operation},
		{"pint", _pint},
		{"swap", swap},
		{"nop", nop},
		{"add", add},
		{NULL, NULL}
	};

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
					/*valid instruction found*/
			*flag = 1;
			/*break;*/
		}
		if (instructions[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			*flag = 0;/*for unknown instruction*/
		}
	}
}
