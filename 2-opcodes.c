#include "monty.h"

/**
 * add - a function to add the top two elements of the stack
 * @stack: pointer to stack
 * @line_number: ints to be added
 * Return: reslut of two ints
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (top < 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n += (*stack)->next->n;
	pop(stack, line_number);
}

/**
 * nop - a function that does nothing
 * @stack: pointer to stack
 * @line_number: voided
 * Return: void
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - a fuction that subtracts the top element from the
 * second element of the stack
 * @stack: pointer to stack
 * @line_number: values to be subtracted
 * Return: void
 */

void sub(stack_t **stack, unsigned int line_number)
{
	if (top < 1)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}

/**
 * divide - a function that devides the 2 elements at the top of the stack
 * @stack: pointer to stack
 * @line_number: elements to be divided
 * Return: void
 */

void divide(stack_t **stack, unsigned int line_number)
{
	if (top < 1)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}
