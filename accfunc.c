#include "monty.h"

/**
 * lec_file - read file and execute commands
 * @filename: pathname to file
 * @stack: pointer a la parte superior del stack (pila(
 */
void lec_file(char *filename, stack_t **stack)
{
	char *buffer = NULL;
	char *line;
	size_t i = 0;
	unsigned int line_count = 1;
	instruct_func s;
	int read;
	FILE *file = fopen(filename, "r");

	if (file == NULL)
		error_salida(2, *stack);

	while ((read = getline(&buffer, &i, file)) != -1)
	{
		line = parse_line(buffer);
		if (line == NULL)
		{
			line_count++;
			continue;
		}
		s = get_op_func(line);
		if (s == NULL)
			error_salida(3, *stack);

		s(stack, line_count);
		line_count++;
	}
	free(buffer);
}
/**
 * get_op_func -  checks opcode and returns the correct function
 * @str: the opcode
 *
 * Return: returns a function, or NULL on failure
 */
instruct_func get_op_func(char *str)
{
	int i;

	instruction_t instruct[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL},
	};

	i = 0;
	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
	{
		i++;
	}

	return (instruct[i].f);
}
/**
 * parse_line - parses a line for an opcode and arguments
 * @line: the line to be parsed
 *
 * Return: returns the opcode or null on failure
 */
char *parse_line(char *line)
{
	char *op_code;

	op_code = strtok(line, "\n ");
	if (op_code == NULL)
		return (NULL);
	return (op_code);
}