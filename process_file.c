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
	int line_num = 0, value;

	while (readLine(file, line))
	{
		line_num++;
		parseLine(line, &instruction, &value);

		if (instruction != NULL)
		{
			if (strcmp(instruction, "push") == 0)
			{
				handlePush(value, line_num);
			}
			else
			{
				handleInstruction(instruction, line_num);
			}
		}
	}
}
