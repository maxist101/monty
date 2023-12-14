#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]);
MontyMilieu_t env;

/**
 * main - interpreter
 * @argc: argument numbers
 * @argv: file location
 * Return: 0
 */
int main(int argc, char *argv[])
{
char *payload;
FILE *file;
size_t size_file = 0;
ssize_t init_line = 1;
stack_t *stack = NULL;
unsigned int num_ln = 0;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
file = fopen(argv[1], "r");
env.file = file;
if (!file)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
while (init_line > 0)
{
payload = NULL;
init_line = getline(&payload, &size_file, file);
env.payload = payload;
num_ln++;
if (init_line > 0)
{
exe(payload, &stack, num_ln, file);
}
free(payload);
}
stack_free(stack);
fclose(file);
return (0);
}
/*ANTHONY MAXWELL*/
