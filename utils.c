#include "main.h"
/**
 * is_printable - evaluate if a char is printable
 * @c: char to be evaluated
 *
 * return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c);
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
/**
 * append_hex_code - append ascci in hexadecimal code to buffer
 * @buffer: array of chars
 * @i: index at which to start appending
 * @ascii_code: ASSCI CODE
 * return: always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* the hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;
	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];
	return (3);
}
/**
 * is_digit - verifies if a char is a digit
 * @c: char to be evaluated
 *
 * return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/**
 * convert_size_number - cats a number to the specified size
 * @num: number to be casted
 * 2size: number indicating the type to be casted
 *
 * return: casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_short)
		return ((short)num);
	return ((int)num);
}
/**
 * convert_size_unsgnd - casts a number to the specified size
 * @num: number to be casted
 * @size: number indicating the type to be casted
 *
 * return: casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}
