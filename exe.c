#include "monty.h"

int exe(char *payload, stack_t **stack, unsigned int line_number, FILE *file);
/**
 * exe - my code function that execute the opcode
 * @stack: Stack
 * @line_number: Intiger line
 * @file: for the monty program file
 * @payload: payload
 * Return: Null(always else)
 */
int exe(char *payload, stack_t **stack, unsigned int line_number, FILE *file)
{
	instruction_t OPT[] = {
		{"push", my_push},
		{"pall", my_pall},
		{"pint", my_pint},
		{"pop", my_pop},
		{"swap", my_swap},
		{"add", my_add},
		{"nop", my_nop},
		{"sub", my_sub},
		{"div", my_div},
		{"mul", my_mul},
		{"mod", my_mod},
		{"pchar", my_pchar},
		{"pstr", my_pstr},
		{"rotl", my_rotl},
		{"rotr", my_rotr},
		{"queue", my_queue},
		{"stack", my_stack},
		{NULL, NULL},
	};
	unsigned int k = 0;
	char *alx;

	alx = strtok(payload, " \n\t");
	if (alx && alx[0] == '#')
		return (0);
	env.arg = strtok(NULL, " \n\t");
	while (OPT[k].opcode && alx)
	{
		if (strcmp(alx, OPT[k].opcode) == 0)
		{
			OPT[k].f(stack, line_number);
			return (0);
		}
		k++;
	}
	if (alx && OPT[k].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, alx);
		fclose(file);
		free(payload);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}

