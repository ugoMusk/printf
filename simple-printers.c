#include "main.h"

/**
 * print_from_to - prints a range of char addresses
 * @start: starting address
 * @stop: stopping address
 * @except: except address
 *
 * Return: number bytes printed
 */
int print_from_to(char *start, char *stop, char *except)
{
	int add = 0;

	while (start <= stop)
	{
		if (start != except)
			add += _putchar(*start);
		start++;
	}
	return (add);
}

/**
 * print_rev - prints string in reverse
 * @aa: string
 * @params: the parameters struct
 *
 * Return: number bytes printed
 */
int print_rev(va_list aa, params_t *params)
{
	int len, add = 0;
	char *str = va_arg(aa, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			add += _putchar(*str);
	}
	return (add);
}

/**
 * print_rot13 - prints string in rot13
 * @a: string
 * @params: the parameters struct
 *
 * Return: number bytes printed
 */
int print_rot13(va_list aa, params_t *params)
{
	int i, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(aa, char *);
	(void)params;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
