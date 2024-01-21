#include "monty.h"

/**
 * struct instruction_t - opcode and its function
 * @opcodes: the opcode
 */

instruction_t opcodes[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"pchar", pchar},
	{"pstr", pstr},
        {"swap", swap},
        {"add", add},
        {"sub", sub},
        {"div", divide},
        {"mul", multiply},
        {"mod", mod},
	{"rotl", rotl},
	{"rotr", rotr},
	{"stack", stack},
	{"queue", queue},
        {"nop", nop},
        {NULL, NULL}
};

int stack_array[STACK_SIZE];
int top = -1;
int queue_mode = 0;

/**
 * push - a fuction to push an element onto the stack
 * @stack: pointer to stack
 * @line_number: num to be added
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	int val;
	
	if (value == NULL)
	{
		fprintf(stderr, "L%d: stack overflow\n", line_number);
		exit(EXIT_FAILURE);
	}

	val = atoi(value);

	if (top == STACK_SIZE - 1)
	{
		fprintf(stderr, "L%d: Stack overflow\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)[++top].n = val;
}

/**
 * pall - a function to print all values on the stack
 * @stack: pointer to stack
 * @line_number: line to be printed
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	int i;
	
	for (i = top; i >= 0; i--)
	{
		printf("%d\n", (*stack)[i].n);
	}
	(void)line_number;
}

/**
 * pint - function to print the value at the top of the stack
 * @stack: pointer to stack
 * @line_number: value to be printed
 * Return: void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (top == -1)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)[top].n);
}

/**
 * pop - function to remove the top element of the stack
 * @stack: pointer to stack
 * @line_number:  value to be removed
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	if (top == -1)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	top--;
	(void)stack;
}

/**
 * swap - a function to swap the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number - value to be swapped
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (top < 1)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)[top].n;
	(*stack)[top].n = (*stack)[top - 1].n;
	(*stack)[top - 1].n = temp;
}
