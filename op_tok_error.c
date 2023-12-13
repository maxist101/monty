#include "mymonty.h"

/**
 * op_tok_err - last element of op_toks to be an error code in my code.
 * @err_code: store integer as string in op_toks.
 */
void op_tok_err(int err_code)
{
	int tokes_length = 0, i = 0;
	char *str_exit = NULL;
	char **tokes_cent = NULL;

	tokes_length = tokes_len();
	tokes_cent = malloc(sizeof(char *) * (tokes_length + 2));
	if (!tokes_opt)
	{
		malloc_err();
		return;
	}
	while (i < tokes_length)
	{
		tokes_cent[i] = tokes_opt[i];
		i++;
	}
	str_exit = get(err_code);
	if (!str_exit)
	{
		free(tokes_cent);
		malloc_err();
		return;
	}
	tokes_cent[i++] = str_exit;
	tokes_cent[i] = NULL;
	free(tokes_opt);
	tokes_opt = tokes_cent;
}

