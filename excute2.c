#include "monty.h"
/**
 *f_nop - adds a new node at the top of stack
 * @stack: pointer to the head of the list
 * @line_number: line number
 * Return: no return
 */
void f_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 *f_nop - adds a new node at the top of stack
 * @stack: pointer to the head of the list
 * @line_number: line number
 * Return: no return
 */
void f_swap(stack_t **stack, unsigned int line_number)
{
	int h;

	if ((*stack == NULL || (*stack)->next ==  NULL))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(stack);
		free(va.args);
		exit(EXIT_FAILURE);
	}
	h = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = h;
}




