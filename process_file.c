#include "monty.h"

/**
 * processFile - a function to process moty bytecodes
 * @file -pointer to file to be converted
 * Return: monty bytecode
 */

void processFile(FILE *file)
{
	char line[256], *token;
	size_t len;
	int line_num = 0;
	int value;

	while(fgets(line, sizeof(line), file) != NULL)
	{
		line_num++;

		len = strlen(line);
		if (len > 0 && line[len - 1] == '\n')
		{
			line[len -1] = '\0';
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
				fprintf(stderr, "L%d: Error: push requires an argument\n", line_num);
				exit(EXIT_FAILURE);
			}

			value = atoi(token);
			if (value == 0 && *token != '0')
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_num);
				exit(EXIT_FAILURE);
			}

			push(value, line_num);
		}
		else if (strcmp(token, "pall") == 0)
		{
				pall();
		}
		else if (strcmp(token, "pint") == 0)
		{
			pint(line_num);
		}
		else if (strcmp(token, "pop") == 0)
		{
			pop(line_num);
		}
		else if (strcmp(token, "swap") == 0)
		{
			swap(line_num);
		}
		else if (strcmp(token, "add") == 0)
		{
			add(line_num);
		}
		else if (strcmp(token, "sub") == 0)
		{
			sub(line_num);
		}
		else if (strcmp(token, "div") == 0)
		{
			divide(line_num);
		}
		else if (strcmp(token, "nop") == 0)
		{
			nop(line_num);
		}
		else
		{
			fprintf(stderr, "L%d: Error: unknown instruction %s\n", line_num, token);
			exit(EXIT_FAILURE);
		}
	}
}
