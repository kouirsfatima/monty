
#include "monty.h"
/**
 * free_stack - function that frees a stack.
 * @stack: pointer to linked lists
 */
void free_stack(stack_t **stack)
{
if (stack)
	{
	if (*stack)
		{
		while ((*stack)->next)
		{
			(*stack) = (*stack)->next;
			free((*stack)->prev);
		}
		free((*stack));
		(*stack) = NULL;
		}
	}
}
#include "monty.h"
/**
 * *__atoi - convert a string to an integer
 * @argument: pointer to a instruction
 * @stack: pointer to stack list
 * @line_count: number of line in file
 * Return: an integer
 */
int __atoi(char *argument, stack_t *stack, int line_count)
{
	int i = 0, n = 0, neg = 1;

	if (!argument)
	{	fprintf(stderr, "L%d: usage: push integer\n", line_count);
		free(va.args);
		free_stack(&stack);
		fclose(va.file_fb);
		exit(EXIT_FAILURE); }
	if (argument[0] == '-')
	{i++;
		neg = -1; }
	for (; argument[i]; i++)
	{
		if (argument[i] >= '0' && argument[i] <= '9')
			n = n * 10 + (argument[i] - '0');
		else
		{ fprintf(stderr, "L%d: usage: push integer\n", line_count);
			free(va.args);
			free_stack(&stack);
			fclose(va.file_fb);
			exit(EXIT_FAILURE); }
	}
	return (n * neg);
}
























