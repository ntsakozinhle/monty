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

/**
 * pchar - a function that prints the char at the top of the stack
 * @line_num: element to print
 * Return: void
 */

void pchar(int line_num)
{
	int value;

	if (top == -1)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	value = stack[top];

	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (char)value);
}
