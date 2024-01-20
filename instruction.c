#include "monty.h"

/**
 * handleInstruction - a function to handle instructions
 * @instruction: command passed to function
 * @stack: pointer to stack
 * @line_number: line position
 * Return: void
 */

void handleInstruction(char *instruction, stack_t **stack, unsigned int line_number)
{
	size_t i;

	for (i = 0; opcodes[i].opcode; i++)
	{
		if (strcmp(instruction, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d, unknown instruction %s\n", line_number, instruction);
	exit(EXIT_FAILURE);
}
