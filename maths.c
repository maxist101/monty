#include "monty.h"

/**
 * my_add - Adds the top two elements of the stack
 * @nodepointer: nodepointer
 * @line_number: Int Line
 */
void my_add(stack_t **nodepointer, unsigned int line_number)
{
	stack_t *initial;
	stack_t *latter;
	int add;

	if (*nodepointer == NULL || (*nodepointer)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(env.file);
		free(env.payload);
		stack_free(*nodepointer);
		exit(EXIT_FAILURE);
	}

	initial = *nodepointer;
	latter = initial->next;
	add = initial->n + latter->n;

	latter->n = add;
	*nodepointer = latter;
	free(initial);
}
