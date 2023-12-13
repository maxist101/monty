#ifndef MONTY_H
#define MONTY_H

#define MAX 100

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct MontyMilieu -my code for Env for Monty interpreter
 * @arg: value of arg
 * @file: file that points to monty file
 * @payload: line for payload
 * @nofi: flag to change sta queue
 * Description: Thats values int the program for Monty interpreter
 */
typedef struct MontyMilieu
{
	char *arg;
	FILE *file;
	char *payload;
	int nofi;
} MontyMilieu_t;

extern MontyMilieu_t env;

void my_push(stack_t **nodepointer, unsigned int line_number);
void my _pall(stack_t **nodepointer, unsigned int line_number);
void my_pint(stack_t **nodepointer, unsigned int line_number);
void my_pop(stack_t **nodepointer, unsigned int line_number);
void my_swap(stack_t **nodepointer, unsigned int line_number);
void my_add(stack_t **nodepointer, unsigned int line_number);
void my_nop(stack_t **nodepointer, unsigned int line_number);
void my_sub(stack_t **nodepointer, unsigned int line_number);
void my_div(stack_t **nodepointer, unsigned int line_number);
void my_mul(stack_t **nodepointer, unsigned int line_number);
void my_mod(stack_t **nodepointer, unsigned int line_number);
void my_pchar(stack_t **nodepointer, unsigned int line_number);
void my_pstr(stack_t **nodepointer, unsigned int line_number);
void my_rotr(stack_t **nodepointer, __attribute__((unused)) unsigned int line_number);
void my_rotl(stack_t **nodepointer, __attribute__((unused)) unsigned int line_number);
void my_stack(stack_t **nodepointer, unsigned int line_number);
void my_queue(stack_t **nodepointer, unsigned int line_number);
void pop_queue(stack_t **nodepointer, int n);
int pop_exe(char *payload, stack_t **stack, unsigned int count, FILE *file);
void stack_free(stack_t *nodepointer);
void pop_queue(stack_t **nodepointer, int n);
void h_ode(stack_t **nodepointer, int n);

#endif /*_MONTY_H*/
