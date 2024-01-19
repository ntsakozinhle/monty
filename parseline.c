#include "monty.h"

/**
 * parseLine - a function to parse a line and extract
 * the instruction and value
 * @line: line to be called to function
 * @instruction: action to be given to line
 * @value: assigned to line
 * Return: void
 */

void parseLine(char *line, char **instruction, int *value)
{
	char *token;

	token = strtok(line, " ");
	*instruction = token;

	if (*instruction == NULL || (*instruction)[0] == '#')
	{
		*instruction = NULL;
		return;
	}

	token = strtok(NULL, " ");
	*value = (token == NULL) ? 0 : atoi(token);
}
