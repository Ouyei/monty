#include "monty.h"
/**
 * error_salida - Prints erro messages.
 * @error_code: The error codes are the following.
 */
void error_salida(unsigned int error_code, ...)
{
	/*va_list ag;*/
	char *error_opcode;
	unsigned int line_count;

	va start (ag, error_code)
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
					va_arg(ag, char *));
			break;
		case 3:
			line_count = va_arg(ag, unsigned int);
			error_opcode = va_arg(ag, char *);
			fprintf(stderr, "L%u: unknown instruction %s\n", l_num, error_opcode);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		default:
			break;
	}
	free_dlistint();
	exit(EXIT_FAILURE);
}