#include <stdlib.h>

char *get(int num);
unsigned int abc(int);
int numbase_get(unsigned int num, unsigned int base);
void buff_fill(unsigned int num, unsigned int base, char *buff, int buff_size);

/**
 * get - gets a character
 * @num: number to convert
 *
 * Return: newly created string
 */
char *get(int num)
{
	unsigned int camp;
	int length = 0;
	long numl = 0;
	char *nest;

	camp = abc(num);
	length = numbase_get(camp, 10);

	if (num < 0 || numl < 0)
		length++;
	nest = malloc(length + 1); /*my code to create new string */
	if (!nest)
		return (NULL);

	buff_fill(camp, 10, nest, length);
	if (num < 0 || numl < 0)
		nest[0] = '-';

	return (nest);
}

/**
 * abc - value of an integer
 * @i: integer to get absol
 *
 * Return: unsigned integer abs rep of i
 */
unsigned int abc(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * numbase_get - gets length of buffer needed for an unsigned int
 * @num: number to get length needed for
 * @base: base of number representation used by buffer
 *
 * Return: integer containing length of buffer needed (doesn't contain null bt)
 */
int numbase_get(unsigned int num, unsigned int base)
{
	int len = 1; /* all numbers contain atleast one digit */

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * buff_fill - fills buffer with correct numbers up to base 36
 * @num: number to convert to string given base
 * @base: base of number used in conversion, only works up to base 36
 * @buff: buffer to fill with result of conversion
 * @buff_size: size of buffer in bytes
 *
 * Return: always void.
 */
void buff_fill(unsigned int num, unsigned int base, char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9) /* return lowercase ascii val representation */
			buff[i] = rem + 87; /* 10 will be a, 11 = b, ... */
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}

