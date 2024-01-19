#include "monty.h"

/**
 * handleInstruction - a function to handle instructions
 * @instruction: command passed to function
 * @value: value passed to line
 * @line_num: line position
 * Return: void
 */

void handleInstruction(char *instruction, int line_num)
{
	switch (instruction[0])
	{
		case 'p':
			if (strcmp(instruction, "pall") == 0)
				pall();
			else if (strcmp(instruction, "pint") == 0)
				pint(line_num);
			else if (strcmp(instruction, "pop") == 0)
				pop(line_num);
			break;
		case 's':
			if (strcmp(instruction, "swap") == 0)
				swap(line_num);
			else if (strcmp(instruction, "sub") == 0)
				sub(line_num);
			break;
		case 'a':
			if (strcmp(instruction, "add") == 0)
				add(line_num);
			break;
		case 'd':
			if (strcmp(instruction, "div") == 0)
				divide(line_num);
			break;
		case 'm':
			if (strcmp(instruction, "mul") == 0)
				multiply(line_num);
			else if (strcmp(instruction, "mod") == 0)
				mod(line_num);
			break;
		case 'n':
			if (strcmp(instruction, "nop") == 0)
				nop(line_num);
			break;
		default:
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, instruction);
			exit(EXIT_FAILURE);
	}
}
