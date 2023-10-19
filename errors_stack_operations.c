#include "monty.h"

/**
 * error2 - errors handling
 * @error_code: The error codes are the following:
 * (6) => When stack is empty to pint.
 * (7) => When stack is empty to pop.
 * (8) => When stack is too short for operation.
 * (9) => Division by zero.
 */
void error2(int error_code, ...)
{
	va_list fr;
	char *x;
	int number;

	va_start(fr, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(fr, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(fr, int));
			break;
		case 8:
			number = va_arg(fr, unsigned int);
			x = va_arg(fr, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", number, x);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(fr, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * error1 - To Print appropiate error messages.
 * @error_code: The error codes are the following:
 * (1) => When no file given or more than one file to the program.
 * (2) => File provided cannot be opened or read.
 * (3) => File provided contains an invalid instruction.
 * (4) => When program is unable to malloc more memory.
 * (5) => When not integer parameter passed to the instruction "push".
 * (6) => When stack it empty to pint.
 * (7) => When stack is empty to pop.
 * (8) => When stack is too short for operation.
 */
void error1(int error_code, ...)
{
	va_list fr;
	char *x;
	int number;

	va_start(fr, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(fr, char *));
			break;
		case 3:
			number = va_arg(fr, int);
			x = va_arg(fr, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", number, x);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(fr, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * str_error - errors handling.
 * @error_code: The error codes are the following:
 * (10) ~> The node number is not in ASCII bounds.
 * (11) ~> Empty stack.
 */
void str_error(int error_code, ...)
{
	va_list fr;
	int number;

	va_start(fr, error_code);
	number = va_arg(fr, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", number);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", number);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * ModNodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void ModNodes(stack_t **stack, unsigned int line_number)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error2(8, line_number, "mod");

	if ((*stack)->n == 0)
		error2(9, line_number);
	(*stack) = (*stack)->next;
	s = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * MulNodes - Adds stack's top two elements.
 * @stack: Pointer to a pointer pointing to stack's top node.
 * @line_number: Integer which represent opcode's line number.
 */

void MulNodes(stack_t **stack, unsigned int line_number)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error2(8, line_number, "mul");

	(*stack) = (*stack)->next;
	s = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
