#include "monty.h"

/**
 * handlePush - a function to handle the "push" instruction
 * @value: to be added to line
 * @line_number: position of line
 * Return: void
 */

void handlePush(int value, unsigned int line_number, stack_t **stack)
{

	if (value ==0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	push(stack, line_number);
}
