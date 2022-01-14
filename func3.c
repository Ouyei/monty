#include "monty.h"
/**
 * mult - multiplica dos numeros
 *@stack: pointer to a top node
 *@n_line: opcode line number
 */
void mult(stack_t **stack, unsigned int n_line)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_salida2(8, n_line, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
