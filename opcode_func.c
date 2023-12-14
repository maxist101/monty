#include "monty.h"
void error_manager(unsigned int line_number, stack_t **nodepointer);
void my_push(stack_t **nodepointer, unsigned int line_number);
void my_pint(stack_t **nodepointer, unsigned int line_number);
void my_pop(stack_t **nodepointer, unsigned int line_number);
void my_swap(stack_t **nodepointer, unsigned int line_number);

/**
 * error_manager - Hmy code to manage/handle errors
 * @line_number: Int line number where possibility can occur
 * @nodepointer: nodepointer
 */
void error_manager(unsigned int line_number, stack_t **nodepointer)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
fclose(env.file);
free(env.payload);
if (*nodepointer != NULL)
{
stack_free(*nodepointer);
}

exit(EXIT_FAILURE);
}

/**
 * my_push -My code Function that adds node
 * @nodepointer: nodepointer
 * @line_number: Int line number where possibility can occur
 */
void my_push(stack_t **nodepointer, unsigned int line_number)
{
size_t jan;
int yep; /* VARAIBLE DECALARATION*/

if (!env.arg || !*env.arg)
{
if (*nodepointer == NULL)
{
return;
}

error_manager(line_number, nodepointer);
}

for (jan = (env.arg[0] == '-'); env.arg[jan]; ++jan)
{
if (!isdigit(env.arg[jan]))
{
error_manager(line_number, nodepointer);
}
}

yep = atoi(env.arg);

if (env.nofi == 0)
{
in_node(nodepointer, yep);
}
else
{
pop_queue(nodepointer, yep);
}
}
/**
 *my_pint - mu code Function to  print top
 * @nodepointer: nodepointer
 * @line_number: where possiblity can occure inlin int
 * Return: Null
 */
void my_pint(stack_t **nodepointer, unsigned int line_number)
{
if (*nodepointer == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
fclose(env.file);
free(env.payload);
stack_free(*nodepointer);
exit(EXIT_FAILURE);
}
printf("%d\n", (*nodepointer)->n);
}
/**
 *my_pop - my code Function to  print top
 * @nodepointer: nodepointer
 * @line_number: where possiblity can occure inlin int
 * Return: Null
 */
void my_pop(stack_t **nodepointer, unsigned int line_number)
{
stack_t *lib;

if (*nodepointer == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
fclose(env.file);
free(env.payload);
stack_free(*nodepointer);
exit(EXIT_FAILURE);
}
lib = *nodepointer;
*nodepointer = lib->next;
free(lib);
}
/**
 *my_swap - my code Function to  print top
 * @nodepointer: nodepointer
 * @line_number: where possiblity can occure inlin int
 * Return: Null
 */
void my_swap(stack_t **nodepointer, unsigned int line_number)
{
stack_t *initial, *latter;
int camp;

if (*nodepointer == NULL || (*nodepointer)->next == NULL)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
fclose(env.file);
free(env.payload);
stack_free(*nodepointer);
exit(EXIT_FAILURE);
}

initial = *nodepointer;
latter = initial->next;
camp = initial->n;

initial->n = latter->n;
latter->n = camp;
}
/*ANTHONY MAXWELL*/
