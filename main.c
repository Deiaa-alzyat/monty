#include "monty.h"
stack_t *hd = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	opnfile(argv[1]);
	free_nodes();
	return (0);
}

/**
 * create_node - To create a node.
 * @n: Number to go in the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		error1(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - To make free nodes in the stack.
 */
void free_nodes(void)
{
	stack_t *temperary;

	if (hd == NULL)
		return;

	while (hd != NULL)
	{
		temperary = hd;
		hd = hd->next;
		free(temperary);
	}
}

/**
 * AddToQueue - Adding a node to the queue.
 * @new_node: Pointer to new node.
 * @ln: opcode's line number.
 */
void AddToQueue(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
	while (temperary->next != NULL)
		temperary = temperary->next;

	temperary->next = *new_node;
	(*new_node)->prev = temperary;
}
