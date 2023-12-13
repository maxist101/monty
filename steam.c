#include "monty.h"

/**
 * in_node - mu code Func that adds node
 * @nodepointer: nodepointer
 * @n: the recent value
 * Return: Null
 */
void in_node(stack_t **nodepointer, int n)
{
	stack_t *steam, *beam;

	beam = *nodepointer;
	steam = malloc(sizeof(stack_t));
	if (steam == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	if (beam)
		beam->prev = steam;

	steam->n = n;
	steam->next = *nodepointer;
	steam->prev = NULL;
	*nodepointer = steam;
}

/**
 * pop_queue - my code Func that add node to the bottom
 * @nodepointer: nodepointer
 * @n: the recent value
 * Return: Null
 */
void pop_queue(stack_t **nodepointer, int n)
{
	stack_t *steam, *beam;

	beam = *nodepointer;
	steam = malloc(sizeof(stack_t));
	if (steam == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	steam->n = n;
	steam->next = NULL;

	if (beam)
	{
		while (beam->next)
			beam = beam->next;
	}

	if (!beam)
	{
		*nodepointer = steam;
		steam->prev = NULL;
	}
	else
	{
		beam->next = steam;
		steam->prev = beam;
	}
}
