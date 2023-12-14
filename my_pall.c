#include "monty.h"
/**
 * my_pall - Func prints stack info
 * @nodepointer: nodepointer
 * @line_number: Int line
 * Return: Null
 */
void my_pall(stack_t **nodepointer, unsigned int line_number)
{
	stack_t *abj;
	(void)line_number;

	abj = *nodepointer;
	if (abj == NULL)
	{
		/* Stack is empty, handle accordingly*/
		return;
	}

	/* Continue with the loop to print stack values*/
	while (abj)
	{
		printf("%d\n", abj->n);
		abj = abj->next;
	}
}
