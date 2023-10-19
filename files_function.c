#include "monty.h"

/**
 * rdfile - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void rdfile(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = prsline(buffer, line_number, format);
	}
	free(buffer);
}

/**
 * prsline - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int prsline(char *buffer, int line_number, int format)
{
	char *opcode, *val;
	const char *delim = "\n ";

	if (buffer == NULL)
		error1(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	val = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_function(opcode, val, line_number, format);
	return (format);
}

/**
 * opnfile - for file openning.
 * @f_nam: the name path for the file.
 * Return: void
 */

void opnfile(char *f_nam)
{
	FILE *fd = fopen(f_nam, "r");

	if (f_nam == NULL || fd == NULL)
		error1(2, f_nam);

	rdfile(fd);
	fclose(fd);
}

/**
 * call_fun - Calls the required function.
 * @func: Pointer to function about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: the instruction line numeber.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */

void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flg;
	int k;

	flg = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flg = -1;
		}
		if (val == NULL)
			error1(5, ln);
		for (k = 0; val[k] != '\0'; k++)
		{
			if (isdigit(val[k]) == 0)
				error1(5, ln);
		}
		node = create_node(atoi(val) * flg);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			AddToQueue(&node, ln);
	}
	else
		func(&hd, ln);
}

/**
 * find_function - find the appropriate function for the opcode
 * @opcode: opcode
 * @val: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */

void find_function(char *opcode, char *val, int ln, int format)
{
	int k;
	int flg;

	instruction_t func_list[] = {
		{"push", AddToStack},
		{"pall", PrintStack},
		{"pint", PrntTop},
		{"pop", PopTop},
		{"nop", nop},
		{"swap", SwpNodes},
		{"add", AddNodes},
		{"sub", SubNodes},
		{"div", DivNodes},
		{"mul", MulNodes},
		{"mod", ModNodes},
		{"pchar", PrntChar},
		{"pstr", prntString},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flg = 1, k = 0; func_list[k].opcode != NULL; k++)
	{
		if (strcmp(opcode, func_list[k].opcode) == 0)
		{
			call_fun(func_list[k].f, opcode, val, ln, format);
			flg = 0;
		}
	}
	if (flg == 1)
		error1(3, ln, opcode);
}
