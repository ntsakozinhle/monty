#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100

extern int stack[STACK_SIZE];
extern int top;
extern char *value;
extern struct instruction_t opcodes[];
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;


int main (int argc, char *argv[]);
int readLine(FILE *file, char *line);
void parseLine(char *line, char **instruction, int *value);
void handlePush(int value, unsigned int line_number, stack_t **stack);
void handleInstruction(char *instruction, stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void multiply(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void processFile(FILE *file);


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct instruction_t - opcode and its function
 * @opcodes: the opcode
 */

instruction_t opcodes[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"pchar", pchar},
	{"swap", swap},
	{"add", add},
	{"sub", sub},
	{"divide", divide},
	{"mul", multiply},
	{"mod", mod},
	{"nop", nop},
	{NULL, NULL}
};


#endif
