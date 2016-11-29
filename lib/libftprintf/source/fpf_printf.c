/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 17:35:42 by gvillat           #+#    #+#             */
/*   Updated: 2016/09/27 17:35:43 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fpf_printf.h"

int		fpf_get_flags(PF *argu, va_list ap)
{
	argu->index = 0;
	while (argu->format[argu->index] == '#' || argu->format[argu->index] == '0'
		|| argu->format[argu->index] == '-' || argu->format[argu->index] == '+'
		|| argu->format[argu->index] == ' ' || argu->format[argu->index] == 'h'
		|| argu->format[argu->index] == 'l' || argu->format[argu->index] == 'j'
		|| argu->format[argu->index] == 'z' || argu->format[argu->index] == '.'
		|| argu->format[argu->index] == '*' ||
		fpf_isdigit(argu->format[argu->index]))
	{
		fpf_check_flags(argu);
		fpf_check_width(argu, ap);
		fpf_check_precision(argu, ap);
		fpf_check_length(argu);
	}
	fpf_check_spec(argu);
	if (argu->index == fpf_strlen(argu->format))
		return (-1);
	return (argu->index);
}

int		fpf_check_format(char *str, PF *argument, va_list ap)
{
	int i;
	SPE spe[128];

	i = -1;
	fpf_init_spe_tab(spe);
	while (str[++i] != '\0')
	{
		if (str[i] == '%')
		{
			fpf_init_argument(argument);
			argument->format = &str[++i];
			if (fpf_get_flags(argument, ap) == -1)
				return (-1);
			spe->spe[argument->spec](argument, ap);
			i += argument->index;
		}
		else if (str[i] != '%' && str[i] != '\0')
			fpf_buf(str[i], argument);
	}
	return (0);
}

int		fpf_printf(const char *format, ...)
{
	va_list ap;
	PF		argument;

	if (!format)
		return (-1);
	g_i = 0;
	argument.ret = 0;
	va_start(ap, format);
	fpf_init_argument(&argument);
	fpf_init_buff();
	fpf_check_format((char*)format, &argument, ap);
	if (g_i)
		fpf_display(&argument);
	va_end(ap);
	return (argument.ret);
}
