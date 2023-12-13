#include "mymonty.h"
#include <string.h>

void stack_free(stack_t **stack);
int in_stack(stack_t **stack);
int mode(stack_t *stack);

/**
 * stack_free - Frees a stack_t stack.
 * @stack: A pointer to the top (stack) or bottom (queue) of a stack_t.
 */
void stack_free(stack_t **stack)
{
	stack_t *camp = *stack;

	while (*stack)
	{
		camp = (*stack)->next;
		free(*stack);
		*stack = camp;
	}
}

/**
 * in_stack - Initializes a stack_t stack
 * @stack: A pointer to an unitialized stack_t stack.
 * Return: If an error occurs - EXIT_FAILURE.
 */
int in_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (malloc_err());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * mode - Checks if a stack_t linked list is in stack or queue mode.
 * @stack: A pointer to the top (stack) or bottom (queue)
 * Return: If the stack_t is in stack mode
 */
int mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
