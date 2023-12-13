#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **tokes_opt = NULL;

/**
 * main - entry point to my monty program
 *
 * @argc: count of arguments
 * @argv: pointer to array of char pointers
 *
 * Return: (EXIT_SUCCESS)always on success (EXIT_FAILURE) on error
 */
int main(int argc, char **argv)
{
FILE *fd_script = NULL;
int code_terminate = EXIT_SUCCESS;
if (argc != 2)
return (use_err());
fd_script = fopen(argv[1], "r");
if (fd_script == NULL)
return (open_err(argv[1]));
code_terminate = exe_monty(fd_script);
fclose(fd_script);
return (code_terminate);
}
