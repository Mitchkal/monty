#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
int flag = 1;
/**
 * main- monty interpreter
 * @argc: the argument count
 * @argv: the supplied argument
 * Return: 1 or 0
 */

int main(int argc, char *argv[])
{
	FILE *file = NULL;
	unsigned int line_number = 0;
	char *file_name = NULL, *opcode = NULL;
	int push_argument = 0;
	size_t line_size = 0;
	ssize_t nread;
	char *line = NULL, *arg_str = NULL;
	const char *delim = " \t\n\r";
	stack_t *stack = NULL;

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	file_name = argv[1];
	if (access(file_name, F_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	file = fopen(file_name, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	while (flag == 1 && (nread = getline(&line, &line_size, file)) != -1)
	{
		line_number++, opcode = strtok(line, delim);
		if (opcode == NULL)
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			arg_str = strtok(NULL, delim);
			if (arg_str == NULL || !is_valid_number(arg_str))
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				free(line), fclose(file), free_stack(stack);
				exit(EXIT_FAILURE);
			}
			push_argument = atoi(arg_str);
			push_op(&stack, line_number, push_argument);
			continue;
		}
		process_command(&stack, opcode, line_number);
	}
	fclose(file), free(line), free_stack(stack);
	(flag == 2) ? exit(EXIT_FAILURE) : exit(EXIT_SUCCESS);
}
