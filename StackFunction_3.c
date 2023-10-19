#include "monty.h"

/**
 * prntString - To Print a string.
 * @stack: Pointer to a pointer pointing to stack's top node.
 * @ln: Integer represent the opcode's line number.
 */
void prntString(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int asci;
	stack_t *temperary;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temperary = *stack;
	while (temperary != NULL)
	{
		asci = temperary->n;
		if (asci <= 0 || asci > 127)
			break;
		printf("%c", asci);
		temperary = temperary->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates stack's first node to the bottom.
 * @stack: Pointer to a pointer pointing to stack's top node.
 * @ln: Integer represent opcode's line number.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *temperary;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temperary = *stack;
	while (temperary->next != NULL)
		temperary = temperary->next;

	temperary->next = *stack;
	(*stack)->prev = temperary;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotr - Rotates stack's last node to the top.
 * @stack: Pointer to a pointer pointing to stack's top node.
 * @ln: Integer represent opcode's line number.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *temperary;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temperary = *stack;

	while (temperary->next != NULL)
		temperary = temperary->next;

	temperary->next = *stack;
	temperary->prev->next = NULL;
	temperary->prev = NULL;
	(*stack)->prev = temperary;
	(*stack) = temperary;
}
