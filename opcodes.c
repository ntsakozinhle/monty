#include "monty.h"

int stack[STACK_SIZE];
int top = -1;

/**
 * push - a fuction to push an element onto the stack
 * @value: int to be pushed
 * @line_num: num to be added
 * Return: void
 */

void push(int value, int line_num)
{
	if (top == STACK_SIZE - 1)
	{
		fprintf(stderr, "L%d Error: Stack overflow\n", line_num);
		exit(EXIT_FAILURE);
	}

	stack[++top] = value;
}

/**
 * pall - a function to print all values on the stack
 * Return: void
 */

void pall(void)
{
	int i;
	
	for (i = top; i >= 0; i--)
	{
		printf("%d\n", stack[i]);
	}
}

/**
 * pint - function to print the value at the top of the stack
 * @line_num: value to be printed
 * Return: void
 */

void pint(int line_num)
{
	if (top == -1)
	{
		fprintf(stderr, "L%d Error: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", stack[top]);
}

/**
 * pop - function to remove the top element of the stack
 * @line_num:  value to be removed
 * Return: void
 */

void pop(int line_num)
{
	if (top == -1)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	top--;
}

/**
 * swap - a function to swap the top two elements of the stack
 * @line_num - value to be swapped
 * Return: void
 */

void swap(int line_num)
{
	int temp;

	if (top < 1)
	{
		fprintf(stderr, "L%d: Error: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp = stack[top];
	stack[top] = stack[top - 1];
	stack[top - 1] = temp;
}
