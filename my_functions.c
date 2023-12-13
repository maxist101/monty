#include "monty.h"

void my_push(stack_t **stack, unsigned int line_number);
void my_pall(stack_t **stack, unsigned int line_number);
void my_pint(stack_t **stack, unsigned int line_number);
void my_pop(stack_t **stack, unsigned int line_number);
void my_swap(stack_t **stack, unsigned int line_number);

/**
 * my_push - my code to pushe value to the linked list
 * @stack: pointer to the top mode link list
 * @line_number: working line number of a Monty file.
 */
void my_push(stack_t **stack, unsigned int line_number)
{
	stack_t *camp, *rcent;
	int k;

	rcent = malloc(sizeof(stack_t));
	if (rcent == NULL)
	{
		op_tok_err(malloc_err());
		return;
	}

	if (tokes_opt[1] == NULL)
	{
		op_tok_err(no_err(line_number));
		return;
	}

	for (k = 0; tokes_opt[1][k]; k++)
	{
		if (tokes_opt[1][k] == '-' && k == 0)
			continue;
		if (tokes_opt[1][k] < '0' || tokes_opt[1][k] > '9')
		{
			op_tok_err(no_err(line_number));
			return;
		}
	}
	rcent->n = atoi(tokes_opt[1]);

	if (mode(*stack) == STACK) /* MY CODE INSERTS STACK at THE FRONT */
	{
		camp = (*stack)->next;
		rcent->prev = *stack;
		rcent->next = camp;
		if (camp)
			camp->prev = rcent; /*COMPARING*/
		(*stack)->next = rcent;
	}
	else
	{
		camp = *stack;  /* MY CODE TO INSERT  QUEUE THE  END... */
		while (camp->next) /*CONDITIONAL*/
			camp = camp->next;
		rcent->prev = camp;
		rcent->next = NULL;
		camp->next = rcent;
	}
}

/**
 * my_pall - my pall code to rint value of a stack_t
 * @stack: pointer to mode node
 * @line_number: current working line..
 */
void my_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *camp = (*stack)->next;

	while (camp)
	{
		printf("%d\n", camp->n);
		camp = camp->next;
	}
	(void)line_number;
}

/**
 * my_pint - my code to print the value
 * @stack:  pointer to mode node
 * @line_number: number: current working line..
 */
void my_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		op_tok_err(err_pint(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}


/**
 * my_pop - my code to removes value element
 * @stack:  pointer to mode node
 * @line_number: number: current working line..
 */
void my_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		op_tok_err(err_pop(line_number));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * my_swap - Swaps two value elementss
 * @stack:  pointer to mode node
 * @line_number: number: current working line..
 */
void my_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *camp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		op_tok_err(stackz_err(line_number, "swap"));
		return;
	}

	camp = (*stack)->next->next;
	(*stack)->next->next = camp->next;
	(*stack)->next->prev = camp;
	if (camp->next)
		camp->next->prev = (*stack)->next;
	camp->next = (*stack)->next;
	camp->prev = *stack;
	(*stack)->next = camp;
}
