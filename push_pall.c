#include "monty.h"

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

/**
 * processFile - function to process monty bytecodes
 * file: pointer to file to process
 * Return: monty bytecode
 */

void processFile(FILE *file)
{
	char line[256], *token;
	size_t len;
	int line_num = 0;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_num++;

		len = strlen(line);
		if (len > 0 && line[len - 1] == '\n')
		{
			line[len - 1] = '\0';
		}

		token = strtok(line, " ");
		if (token == NULL || token[0] == '#')
		{
			continue;
		}

		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, " ");
			if (token == NULL)
			{
				fprintf(stderr, "Error: L%d: push requires an argument\n", line_num);
				exit(EXIT_FAILURE);
			}
			push(atoi(token));
		}
		else if (strcmp(token, "pall") == 0)
		{
			pall();
		}
		else
		{
			fprintf(stderr, "Error: L%d: unknown instruction %s\n", line_num, token);
			exit(EXIT_FAILURE);
		}
	}
}
