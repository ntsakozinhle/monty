#include "monty.h"

/**
 * multiply - a function the multiplies the top 2
 * elements in the stack
 * @stack: pointer to stack
 * @line_number: value to be multiplied
 * Return: void
 */

void multiply(stack_t **stack, unsigned int line_number)
{
	if (top < 1)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mod - a function to compute the remainder of division of
 * top 2 elements
 * @stack: pointer to stack
 * @line_number: elements to divide
 * Return: void
 */

void mod(stack_t **stack, unsigned int line_number)
{
	if (top < 1)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}

/**
 * pchar - a function that prints the char at the top of the stack
 * @stack: pointer to stack
 * @line_number: element to print
 * Return: void
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	if (top == -1)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;

	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (char)value);
}
