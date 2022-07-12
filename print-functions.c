#include "main.h"

/**
 * print_char - prints character
 * @aa: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_char(va_list aa, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, add = 0, ch = va_arg(aa, int);

	if (params->minus_flag)
		add += _putchar(ch);
	while (pad++ < params->width)
		add += _putchar(pad_char);
	if (!params->minus_flag)
		add += _putchar(ch);
	return (add);
}

/**
 * print_int - prints integer
 * @aa: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_int(va_list aa, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(aa, long);
	else if (params->h_modifier)
		l = (short inti)va_arg(aa, int);
	else
		l = (int)va_arg(aa, int);
	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_string - prints string
 * @aa: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_string(va_list aa, params_t *params)
{
	char *str = va_arg(aa, char *), pad_char = ' ';
	unsigned int pad = 0, add = 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	j = pad = _strlen(str);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				add += _putchar(*str++);
		else
			add += _puts(str);
	}
	while (j++ < params->width)
		add += _putchar(pad_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				add += _putchar(*str++);
		else
			add += _puts(str);
	}
	return (add);
}

/**
 * print_percent - prints string
 * @aa: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_percent(va_list aa, params_t *params)
{
	(void)aa;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - custom format specifier
 * @aa: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_S(va_list aa, params_t *params)
{
	char *str = va_arg(aa, char *);
	char *hex;
	int add = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			add += _putchar('\\');
			add += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				add += _putchar('0');
			add += _puts(hex);
		}
		else
		{
			add += _putchar(*str);
		}
	}
	return (add);
}
