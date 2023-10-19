#include "monty.h"

/**
 * PrntChar - Prints Ascii value.
 * @stack: Pointer to a pointer pointing to stack's top node.
 * @line_number: Integer representing opcode's line number.
 */
void PrntChar(stack_t **stack, unsigned int line_number)
{
	int asci;

	if (stack == NULL || *stack == NULL)
		str_error(11, line_number);

	asci = (*stack)->n;
	if (asci < 0 || asci > 127)
		str_error(10, line_number);
	printf("%c\n", asci);
}

/**
 * AddToStack - Adding a stack's node.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the opcode's line number.
 */
void AddToStack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temperary;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (hd == NULL)
	{
		hd = *new_node;
		return;
	}
	temperary = hd;
	hd = *new_node;
	hd->next = temperary;
	temperary->prev = hd;
}

/**
 * PopTop - removing a stack's node.
 * @stack: Pointer to a pointer pointing to stack's top node.
 * @line_number: Integer representing opcode's line number.
 */
void PopTop(stack_t **stack, unsigned int line_number)
{
	stack_t *temperary;

	if (stack == NULL || *stack == NULL)
		error2(7, line_number);

	temperary = *stack;
	*stack = temperary->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temperary);
}

/**
 * PrntTop - Printing the stack's top node.
 * @stack: Pointer to a pointer pointing to stack's top node.
 * @line_number: Integer which represent the opcode's line number.
 */
void PrntTop(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		error2(6, line_number);
	printf("%d\n", (*stack)->n);
}

/**
 * PrintStack - printing a stack's node.
 * @stack: Pointer to a pointer pointing to stack's top node.
 * @line_number: opcode's line number.
 */
void PrintStack(stack_t **stack, unsigned int line_number)
{
	stack_t *temperary;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temperary = *stack;
	while (temperary != NULL)
	{
		printf("%d\n", temperary->n);
		temperary = temperary->next;
	}
}
