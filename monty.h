#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

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

extern stack_t *hd;
typedef void (*op_func)(stack_t **, unsigned int);
/*file operations*/
void rdfile(FILE *);
int prsline(char *buffer, int line_number, int format);
void opnfile(char *f_nam);
void call_fun(op_func, char *, char *, int, int);
void find_function(char *, char *, int, int);

void PrntChar(stack_t **, unsigned int);
void AddToStack(stack_t **, unsigned int);
void PopTop(stack_t **, unsigned int);
void PrntTop(stack_t **, unsigned int);
void PrintStack(stack_t **, unsigned int);

void SwpNodes(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void SubNodes(stack_t **, unsigned int);
void DivNodes(stack_t **, unsigned int);
void AddNodes(stack_t **, unsigned int);

void prntString(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void rotr(stack_t **, unsigned int);

void error2(int error_code, ...);
void error1(int error_code, ...);
void str_error(int error_code, ...);
void ModNodes(stack_t **, unsigned int);
void MulNodes(stack_t **, unsigned int);

stack_t *create_node(int n);
void free_nodes(void);
void AddToQueue(stack_t **, unsigned int);
#endif
