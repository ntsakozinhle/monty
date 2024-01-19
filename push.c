#include "monty.h"

/**
 * handlePush - a function to handle the "push" instruction
 * @value: to be added to line
 * @line_num: position of line
 * Return: void
 */

void handlePush(int value, int line_num)
{

	if (value ==0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	push(value, line_num);
}
