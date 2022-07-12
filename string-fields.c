#include "main.h"

/* Code Credit : Ugobo Thankgod and Paul Sobande */
/**
 * get_precision - gets the precision from the format string
 * @p: the format string
 * @params: the parameters struct
 * @aa: the argument pointer
 *
 * Return: new pointer
 */
char *get_precision(char *p, params_t *params, va_list aa)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(aa, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			d = d * 10 + (*p++ - '0');
	}
	params->precision = d;
	return (p);
}
