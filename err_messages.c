#include "monty.h"

int use_err(void);
int malloc_err(void);
int open_err(char *filename);
int not_known_err(char *opcode, unsigned int line_number);
int no_err(unsigned int line_number);
int stack_err(unsigned int line_number, char *op_code);
int err_div(unsigned int line_number);
int err_pop(unsigned int line_number);
int err_pchar(unsigned int line_number, char *msg);
int err_pint(unsigned int line_number);

/**
 * use_err - writes usage error messages to sdio.
 *
 * Return: (EXIT_FAILURE)
 */
int use_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * malloc_err - malloc error messages.
 *
 * Return: (EXIT_FAILURE)
 */
int malloc_err(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * open_err - opening file error messages/ file name.
 * @filename: Name of the file failed to open
 *
 * Return: (EXIT_FAILURE)
 */
int open_err(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * not_known_err - unknown instruction error message
 * @opcode: error occurred.
 * @line_number: Line number in Monty where error occured.
 *
 * Return: (EXIT_FAILURE)
 */
int not_known_err(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_err -  monty_push argument error message
 * @line_number: Monty file number where error occurred.
 *
 * Return: (EXIT_FAILURE)
 */
int no_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * err_pop -  error messages for empty stack
 * @line_number: Line number the where error occured.
 *
 * Return: (EXIT_FAILURE)
 */
int err_pop(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * err_pint- pint error messages for empty stacks.
 * @line_number: Line where error occurred.
 *
 * Return: (EXIT_FAILURE)
 */
int err_pint(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * stack_err - function error messages
 * @line_number: Line where error occurred.
 * @op_code: Operational code the error occurred.
 *
 * Return: (EXIT_FAILURE)
 */
int stack_err(unsigned int line_number, char *op_code)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op_code);
	return (EXIT_FAILURE);
}

/**
 * err_div - print the divisional error messages for division by 0.
 * @line_number: Line where error occurred.
 *
 * Return: (EXIT_FAILURE)
 */
int err_div(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * err_pchar - error messages for empty stacks
 * @line_number: Line where error occurred.
 * @msg: error message to print.
 *
 * Return: (EXIT_FAILURE)
 */
int err_pchar(unsigned int line_number, char *msg)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, msg);
	return (EXIT_FAILURE);
}
