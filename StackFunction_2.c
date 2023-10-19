#include "monty.h"

/**
 * SwpNodes - Swaps stack's top two elements.
 * @stack: Pointer to a pointer pointing to stack'S top node.
 * @line_number: Integer representing opcode'S line number.
 */
void SwpNodes(stack_t **stack, unsigned int line_number)
{
	stack_t *temperary;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error2(8, line_number, "swap");
	temperary = (*stack)->next;
	(*stack)->next = temperary->next;
	if (temperary->next != NULL)
		temperary->next->prev = *stack;
	temperary->next = *stack;
	(*stack)->prev = temperary;
	temperary->prev = NULL;
	*stack = temperary;
}

/**
 * nop - Nothing to do.
 * @stack: Pointer to a pointer pointing to stack'S top node.
 * @line_number: Integer representing opcode'S line number.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * SubNodes - Adding stack's top two elements.
 * @stack: Pointer to a pointer pointing to stack's top node.
 * @line_number: Integer which represent the opcode's line number.
 */
void SubNodes(stack_t **stack, unsigned int line_number)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		error2(8, line_number, "sub");


	(*stack) = (*stack)->next;
	s = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * DivNodes - Adding stack's top two elements.
 * @stack: Pointer to a pointer pointing to stack's top node.
 * @line_number: Integer which represent opcode's line number.
 */
void DivNodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error2(8, line_number, "div");

	if ((*stack)->n == 0)
		error2(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * AddNodes - Adding stack's top two elements.
 * @stack: Pointer to a pointer pointing to stack's top node.
 * @line_number: Integer which represent opcode's line number.
 */
void AddNodes(stack_t **stack, unsigned int line_number)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error2(8, line_number, "add");

	(*stack) = (*stack)->next;
	s = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
