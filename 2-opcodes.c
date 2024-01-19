#include "monty.h"

/**
 * add - a function to add the top two elements of the stack
 * @line_num: ints to be added
 * Return: reslut of two ints
 */

void add(int line_num)
{
	if (top < 1)
	{
		fprintf(stderr, "L%d: Error: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	stack[top - 1] += stack[top];
	pop(line_num);
}

/**
 * nop - a function that does nothing
 * @line_num: voided
 * Return: void
 */

void nop(int line_num)
{
	(void)line_num;
}

/**
 * sub - a fuction that subtracts the top element from the
 * second element of the stack
 * @line_num: values to be subtracted
 * Return: void
 */

void sub(int line_num)
{
	if (top < 1)
	{
		fprintf(stderr, "L%d: Error: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	stack[top - 1] -= stack[top];
	pop(line_num);
}

/**
 * divide - a function that devides the 2 elements at the top of the stack
 * @line_num: elements to be divided
 * Return: void
 */

void divide(int line_num)
{
	if (top < 1)
	{
		fprintf(stderr, "L%d: Error: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	if (stack[top] == 0)
	{
		fprintf(stderr, "L%d: Error: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}

	stack[top - 1] /= stack[top];
	pop(line_num);
}
