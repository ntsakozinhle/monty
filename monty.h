#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100

extern int stack[STACK_SIZE];
extern int top;

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


int main (int argc, char *argv[]);
int readLine(FILE *file, char *line);
void parseLine(char *line, char **instruction, int *value);
void handlePush(int value, int line_num);
void handleInstruction(char *instruction, int line_num);
void push(int value, int line_num);
void pall(void);
void pint(int line_num);
void pop(int line_num);
void swap(int line_num);
void add(int line_num);
void sub(int line_num);
void divide(int line_num);
void multiply(int line_num);
void mod(int line_num);
void nop(int line_num);
void processFile(FILE *file);

#endif
