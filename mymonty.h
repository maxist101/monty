#ifndef __MYMONTY_H__
#define __MYMONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

/* THE GLOBAL OPCODE TOKENS */
extern char **tokes_opt;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* MY PRIMARY FUNCTIONS */
void stack_free(stack_t **stackz);
int in_stackz(stack_t **stackz);
int mode(stack_t *stackz);
void tokes_free(void);
unsigned int tokes_len(void);
int exe_monty(FILE *fd_script);
void set_optokesERR(int error_code);

/* OPCODE FUNCTIONS PROTOTYPES */
void my_pall(stack_t **stackz, unsigned int line_number);
void my_push(stack_t **stackz, unsigned int line_number);
void my_pint(stack_t **stackz, unsigned int line_number);
void my_pop(stack_t **stackz, unsigned int line_number);
void my_swap(stack_t **stackz, unsigned int line_number);
void my_nop(stack_t **stackz, unsigned int line_number);
void my_add(stack_t **stackz, unsigned int line_number);
void my_div(stack_t **stackz, unsigned int line_number);
void my_mul(stack_t **stackz, unsigned int line_number);
void my_sub(stack_t **stackz, unsigned int line_number);
void my_mod(stack_t **stackz, unsigned int line_number);
void my_pstr(stack_t **stackz, unsigned int line_number);
void my_pchar(stack_t **stackz, unsigned int line_number);
void my_rotl(stack_t **stackz, unsigned int line_number);
void my_rotr(stack_t **stackz, unsigned int line_number);
void my_queue(stack_t **stackz, unsigned int line_number);
void my_stack(stack_t **stackz, unsigned int line_number);

/* FUNCTIONS LIBRARY */
char **strt(char *strn, char *deli);
char *get(int n);

/* MY ERROR MESSAGES/CODES */
int use_err(void);
int malloc_err(void);
int open_err(char *filename);
int not_known_err(char *opcode, unsigned int line_number);
int no_err(unsigned int line_number);
int err_pop(unsigned int line_number);
int err_pint(unsigned int line_number);
int stackz_err(unsigned int line_number, char *op_code);
int err_div(unsigned int line_number);
int err_pchar(unsigned int line_number, char *msg);

#endif /* __MYMONTY_H__ */

