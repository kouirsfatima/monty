#include "monty.h"

/**
 * execute- function that call the appropriate function based on opcode
 * @stack: pointer to the stack
 * @line_number: number of the current line in the file
 * @opcode: pointer to the opcode
 *  Return: An integer
 */
int execute(stack_t **stack, char *opcode, unsigned int line_number)
{
	unsigned int j = 0;

	instruction_t insts[] = {
		{"push", f_push},
		{"pall", f_pall},
		{"pint", f_pint},
		{"pop", f_pop},
		{"nop", f_nop},
		{"swap", f_swap},
		{NULL, NULL},
	};

	for (j = 0; insts[j].opcode != NULL; j++)
	{
		if (strcmp(opcode, insts[j].opcode) == 0)
		{
			insts[j].f(stack, line_number);
			return (0);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	free_stack(stack);
	fclose(va.file_fb);
	free(va.args);
	exit(EXIT_FAILURE);
	return (1);
}
/**
 * f_push - add node to the stack
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
 */
void f_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	(void)line_number;

	if (stack == NULL)
	{
		return;
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(va.args);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	new->n = va.number;
	new->prev = NULL;

	if (*stack == NULL)
	{
		new->next = NULL;
	}
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new;
}

/**
 * f_pall - return the top of a stack.
 * @stack: pointer to the stack
 * @line_number: number of the current line
 *Return: An integer
 */
void f_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = NULL;
	(void)line_number;

	ptr = *stack;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
/**
 * f_pint- return the top of a stack.
 * @stack: pointer to the stack
 * @line_number: number of the current line
 *Return: An integer
 */
void f_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *pint;

	pint = *stack;

	if (pint == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(stack);
		free(va.args);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", pint->n);
}

/**
 * f_pop- return the top of a stack.
 * @stack: pointer to the stack
 * @line_number: number of the current line
 *Return: An integer
 */
void f_pop(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(stack);
		free(va.args);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
}
