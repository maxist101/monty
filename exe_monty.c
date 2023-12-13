#include "monty.h"
#include <string.h>

void tokes_free(void);
unsigned int tokes_len(void);
int line_empty(char *line, char *deli);
void (*opfunct_get(char *opcode))(stack_t**, unsigned int);
int exe_monty(FILE *fd_script);

/**
 * tokes_free - global free array of the strings.
 */
void tokes_free(void)
{
	size_t i = 0;

	if (tokes_opt == NULL)
		return;

	for (i = 0; tokes_opt[i]; i++)
		free(tokes_opt[i]);

	free(tokes_opt);
}

/**
 * tokes_len - length of the current tokes_len.
 *
 * Return: current tokes_len
 */
unsigned int tokes_len(void)
{
	unsigned int tokes_length = 0;

	while (tokes_opt[tokes_length]) /*compareism*/
		tokes_length++;
	return (tokes_length);
}

/**
 * line_empty - Verifies that a line read contain delim
 * @line: pointer too line.
 * @deli: the string of delim char
 *
 * Return: line only contains deli - 1.
 * else - 0.
 */
int line_empty(char *line, char *deli)
{
	int i;
	int k;

	for (i = 0; line[i]; i++)
	{
		for (k = 0; deli[k]; k++)
		{
			if (line[i] == deli[k])
				break;
		}
		if (deli[k] == '\0')
			return (0);
	}

	return (1);
}

/**
 * opfunct_get - opcode with its func.
 * @opcode: opcode to match...
 *
 * Return: pointer correspon func.
 */
void (*opfunct_get(char *opcode))(stack_t**, unsigned int)
{
	instruction_t funcs[] = {
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
		{"stack", my_stack},
		{"queue", my_queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; funcs[i].opcode; i++)
	{
		if (strcmp(opcode, funcs[i].opcode) == 0)
			return (funcs[i].f);
	}

	return (NULL);
}

/**
 * exe_monty - my fun to run/ execute the monty script.
 * @fd_script: description for open monty script.
 *
 * Return: EXIT_SUCCESS on success(always)
 */
int exe_monty(FILE *fd_script)
{
	stack_t *stackz = NULL;

	ssize_t getline(char **lineptr, size_t *n, FILE *stream);
	char *lines = NULL;
	size_t length = 0, status_terminate = EXIT_SUCCESS;
	unsigned int numb_ln = 0, lentok_prevs = 0;
	void (*func)(stack_t**, unsigned int);

	if (in_stackz(&stackz) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&lines, &length, fd_script) != -1)
	{
		numb_ln++;
		tokes_opt = strt(lines, DELIMS);
		if (tokes_opt == NULL)
		{
			if (line_empty(lines, DELIMS))
				continue;
			stack_free(&stackz);
			return (malloc_err());
		}
		else if (tokes_opt[0][0] == '#')
		{
			tokes_free();
			continue;
		}
		func = opfunct_get(tokes_opt[0]);
		if (func == NULL)
		{
			stack_free(&stackz);
			status_terminate = not_known_err(tokes_opt[0], numb_ln);
			tokes_free();
			break;
		}
		lentok_prevs = tokes_len();
		func(&stackz, numb_ln);
		if (tokes_len() != lentok_prevs)
		{
			if (tokes_opt && tokes_opt[lentok_prevs])
				status_terminate = atoi(tokes_opt[lentok_prevs]);
			else
				status_terminate = EXIT_FAILURE;
			tokes_free();
			break;
		}
		tokes_free();
	}
	stack_free(&stackz);

	if (lines && *lines == 0)
	{
		free(lines);
		return (malloc_err());
	}

	free(lines);
	return (status_terminate);
}
