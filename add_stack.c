#include "monty.h"

/**
 * add_dnodeint - adds a new node at the top of stack
 *
 * @head: pointer to the head of the list
 * @h: line number
 * Return: no return
 */
void add_stack(stack_t **stack, unsigned int h)
{
        stack_t *new_node;
        (void)h;
        
    if (stack == NULL)
    {
        exit(EXIT_FAILURE);
    }

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        exit(EXIT_FAILURE);
    }

    new_node->n = 0;
    new_node->prev = NULL;

    if (*stack == NULL)
    {
        new_node->next = NULL;
    }
    else
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }

    *stack = new_node;
    return;
}


