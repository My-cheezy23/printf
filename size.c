#include "main.h"
/**
 * get_size - calculates the size to cast the argument
 * by Olive and Keren
 * @format: forward string in which to print the arguments
 * @i: list of arguments to be printed
 *
 * return: precision
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == '1')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i;
	else
		*i = curr_i;
	return (size);
}
