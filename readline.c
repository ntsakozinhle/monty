#include "monty.h"

/**
 * readLine - a function to read a line from the file
 * @file: file name
 * @line: line to be read
 * Return: Always 0
 */

int readLine(FILE *file, char *line)
{
	size_t len;

	if (fgets(line, sizeof(line), file) != NULL)
	{
		len = strlen(line);
		if (len > 0 && line[len -1] == '\n')
		{
			line[len - 1] = '\0';
		}
		return (1);
	}
	return (0);
}
