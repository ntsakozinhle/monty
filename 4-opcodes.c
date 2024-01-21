#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom
 * @stack: pointer to head of stack
 * @line_number: line being executed
 * Return: void
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last, *second_last;

	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		last = *stack;

		while (last->next != NULL)
		{
			second_last = last;
			last = last->next;
		}

		second_last->next = NULL;
		last->prev = NULL;
		last->next = *stack;
		(*stack)->prev = last;
		*stack = last;
	}
}

/**
 * stack - set the format of the data to a stack (LIFO)
 * @stack: pointer to the head of the stack
 * @line_number: line to be executed
 * Return: void
 */

void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	queue_mode = 0;
}

/**
 * queue - set the format of the data to a queue (FIFO)
 * @stack: pointer to the head of stack
 * @line_number: line to be executed
 * Return: void
 */

void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	queue_mode = 1;

}
