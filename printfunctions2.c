#include "main.h"
/******************** PRINT POINTER **************/
/**
 * print_pointer - prints the value of a pointer variable
 * @types: list a of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates actie flags
 * @width: get width
 * @precision: precision specificatio
 * @size:size specifier
 * return: number of chars printed
 */
int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size);
{
	char extra_c = 0 padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2,
	padd_start = 1; /* length= 2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(SIZE);

	if (addrs == null)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;
	while (num_addrs  > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;
	ind++;
	/*return (write(1, &buffer[i],BUFF_SIZE - i - i));*/
	return (write_pointer(buffer, ind, length,
	width, flags, padd, extra_c, padd_start));
}
/*************************** PRINT NON PRINTABLE *********************/
/**
 * print_non_printable- prints ascii codes in
 * hexa of non printable chars
 * @types: list a of arguments
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * return: number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(SIZE);
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset +=
	append_hexa_code(str[i], buffer, i + offset);
		i++;
	}
	buffer[i + offset] = '\0';
	return (write(1, buffer, i + offset));
}
/*************************** PRINT REVERSE **************************/
/**
 * print_reverse - prints reverse string
 * @types:list a of arguments
 * @buffer: buffer array to handle print
 * @flags: get width
 * @precision: precision specification
 * @size: size specifier
 * return: number of chars printed
 */
int print_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	str = va_arg(types, char *);
	if (str == NULL)
	{
		UNUSED(precision);
		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;
	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);

		count++;
	}
	return (count);
}
/********************** PRINT A STRING IN ROT13 **************/
/**
 * print_rot13string - print a string in rot13
 * @types: list a of arguments
 * @buffer: buffer array to handle print
 * @flags: calculate active flags
 * @width:get width
 * @precision: precision specification
 * @size: size specifier
 * return: numbers of char printed
 */
int print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
       	char in[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] =
	"NOPQRSTUVWXYZA'BCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(width);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}




