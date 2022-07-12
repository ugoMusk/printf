#include "main.h"

/* Code Credit : Ugobo Thankgod & Paul Sobande */
/**
 * _printf - formatted output conversion and print data.
 * @format: input string.
 * Return: number of chars printed.
 */

int _printf(const char *format, ...)
{
	int add = 0;
	va_list a_args;
	char *p, *start;
	params_t params = PARAMS_INIT;

	va_starta_args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, a_args);
		if (*p != '%')
		{
		        add += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params)) /* while char at p is flag char */
		{
			p++; /* next char */
		}
		p = get_width(p, &params, a_args);
		p = get_precision(p, &params, a_args);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			add += print_from_to(start, p, params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			add += get_print_func(p, a_args, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(a_args);
	return (add);
}
