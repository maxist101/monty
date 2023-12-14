#include "monty.h"
void my_mod(stack_t **nodepointer, unsigned int line_number);
void my_pchar(stack_t **nodepointer, unsigned int line_number);
void my_pstr(stack_t **nodepointer, unsigned int line_number);
void my_rotl(stack_t **nodepointer,
		__attribute__((unused)) unsigned int line_number);
void my_rotr(stack_t **nodepointer,
		__attribute__((unused)) unsigned int line_number);
/**
 * my_mod - my code  Func computes the division
 * @nodepointer: nodepointer
 * @line_number: Int line
 * Return: Null
 */
void my_mod(stack_t **nodepointer, unsigned int line_number)
{
	stack_t *map;
	int weight, reserved;

	weight = 0;

	map = *nodepointer;
	while (map)
	{
		map = map->next;
		weight++;
	}
	if (weight < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(env.file);
		free(env.payload);
		stack_free(*nodepointer);
		exit(EXIT_FAILURE);
	}
	map = *nodepointer;
	if (map->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(env.file);
		free(env.payload);
		stack_free(*nodepointer);
		exit(EXIT_FAILURE);
	}
	reserved = map->next->n % map->n;
	map->next->n = reserved;
	*nodepointer = map->next;
	free(map);
}



/**
 * my_pchar - my code  Func that print character from the top
 * @nodepointer: nodepointer
 * @line_number: Int line
 * Return: Null
 */
void my_pchar(stack_t **nodepointer, unsigned int line_number)
{
	stack_t *map;

	map = *nodepointer;
	if (!map)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(env.file);
		free(env.payload);
		stack_free(*nodepointer);
		exit(EXIT_FAILURE);
	}
	if (map->n > 127 || map->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(env.file);
		free(env.payload);
		stack_free(*nodepointer);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", map->n);
}


/**
 * my_pstr - my code Func that prints the str from top
 * @nodepointer: nodepointer
 * @line_number: Int line
 * Return: Null
*/
void my_pstr(stack_t **nodepointer, unsigned int line_number)
{
	stack_t *map;
	(void)line_number;

	map = *nodepointer;
	while (map)
	{
		if (map->n > 127 || map->n <= 0)
		{
			break;
		}
		printf("%c", map->n);
		map = map->next;
	}
	printf("\n");
}



/**
  *_rotl- my code Function that rotates stack
  *@nodepointer: nodepointer
  *@line_number: Int line
  *Return: Null
 */
void my_rotl(stack_t **nodepointer,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *camp = *nodepointer, *reserved;

	if (*nodepointer == NULL || (*nodepointer)->next == NULL)
	{
		return;
	}
	reserved = (*nodepointer)->next;
	reserved->prev = NULL;
	while (camp->next != NULL)
	{
		camp = camp->next;
	}
	camp->next = *nodepointer;
	(*nodepointer)->next = NULL;
	(*nodepointer)->prev = camp;
	(*nodepointer) = reserved;
}



/**
  *my_rotr - my code Function that rotate stack
  *@nodepointer:nodepointer
  *@line_number: Int num
  *Return: Null
 */
void my_rotr(stack_t **nodepointer,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *bit;

	bit = *nodepointer;
	if (*nodepointer == NULL || (*nodepointer)->next == NULL)
	{
		return;
	}
	while (bit->next)
	{
		bit = bit->next;
	}
	bit->next = *nodepointer;
	bit->prev->next = NULL;
	bit->prev = NULL;
	(*nodepointer)->prev = bit;
	(*nodepointer) = bit;
}
