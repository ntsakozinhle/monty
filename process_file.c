#include "monty.h"

/**
 * processFile - a function to process moty bytecodes
 * @file - pointer to file to be converted
 * Return: monty bytecode
 */

void processFile(FILE *file)
{
	char line[256];
	char *instruction;
	int line_number = 0, value;
	stack_t *stack = NULL;

	while (readLine(file, line))
	{
		line_number++;
		parseLine(line, &instruction, &value);

		if (instruction != NULL)
		{
			if (strcmp(instruction, "push") == 0)
			{
				handlePush(value, line_number, &stack);
			}
			else
			{
				handleInstruction(instruction, &stack, line_number);
			}
		}
	}
}
