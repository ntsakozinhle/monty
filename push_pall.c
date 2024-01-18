#include "main.h"

int stack[STACK_SIZE];
int top = -1;

/**
 * push - a fuction to push an element onto the stack
 * @value: int to be pushed
 * Return: void
 */

void push(int value)
{
	if (top == STACK_SIZE - 1)
	{
		fprintf(stderr, "stack overflow: push operation failed\n");
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

	if (top == -1)
	{
		return;
	}
	
	for (i = top; i >= 0; i--)
	{
		printf("%d\n", stack[i]);
	}
}
