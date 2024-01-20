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

	while (*line == ' ' || *line == '\t')
		line++;

	token = strtok(line, " ");
	*instruction = token;

	if (*instruction == NULL || (*instruction)[0] == '#')
	{
		*instruction = NULL;
		return;
	}

	while (token != NULL && (token[strlen(token) - 1] == ' ' || 
				token[strlen(token) - 1] == '\t'))
	{
		token[strlen(token) - 1] = '\0';
		token = strtok(NULL, " ");
	}
	*value = (token == NULL) ? 0 : atoi(token);
}
