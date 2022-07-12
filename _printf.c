#include "main.h"

/* Code Credit: Ugobo ThankGod & Paul Sabonde */
/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */
/* Code Credit: Ugobo ThankGod & Paul Sabonde  */
int _printf(const char *format, ...)
{
	int add = 0;
	va_list aa;
	char *p, *start;
	params_t params = PARAMS_INIT;

	va_start(aa, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, aa);
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
		p = get_width(p, &params, aa);
		p = get_precision(p, &params, aa);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			add += print_from_to(start, p,
								 params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			add += get_print_func(p, aa, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(aa);
	return (add);
}
/* Code Credit: Ugobo ThankGod & Paul Sabonde  */
