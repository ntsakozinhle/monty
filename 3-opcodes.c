#include "monty.h"

/**
 * multiply - a function the multiplies the top 2
 * elements in the stack
 * @line_num: value to be multiplied
 * Return: void
 */

void multiply(int line_num)
{
	if (top < 1)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	stack[top - 1] *= stack[top];
	pop(line_num);
}

/**
 * mod - a function to compute the remainder of division of
 * top 2 elements
 * @line_num: elements to divide
 * Return: void
 */

void mod(int line_num)
{
	if (top < 1)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	if (stack[top] == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}

	stack[top - 1] %= stack[top];
	pop(line_num);
}
