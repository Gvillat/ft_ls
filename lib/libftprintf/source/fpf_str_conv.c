/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_str_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 17:35:56 by gvillat           #+#    #+#             */
/*   Updated: 2016/09/27 17:35:59 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fpf_printf.h"

static int		wstring_handler(PF *argument, va_list ap)
{
	ssize_t len;

	argument->warg = va_arg(ap, wchar_t *);
	argument->spec = 'S';
	if (!argument->warg)
		argument->warg = L"(null)";
	len = fpf_wbytelen(argument->warg);
	if (argument->flags[0] > -1 && argument->flags[0] < len)
		argument->arg = fpf_wstrsub(argument->warg, 0, argument->flags[0]);
	else
		argument->arg = fpf_transform_wchar_in_char(argument->warg);
	return (fpf_print_str(argument));
}

int				string_handler(PF *argument, va_list ap)
{
	ssize_t len;

	if (argument->spec == 'S' || argument->flags[10] == 1)
		return (wstring_handler(argument, ap));
	argument->arg = va_arg(ap, char *);
	if (!argument->arg)
		argument->arg = "(null)";
	len = fpf_strlen(argument->arg);
	if (argument->flags[0] > -1 && argument->flags[0] < len)
		argument->arg = fpf_strsub(argument->arg, 0, argument->flags[0]);
	return (fpf_print_str(argument));
}

int				fpf_print_str(PF *argument)
{
	ssize_t		len;
	ssize_t		padding;
	int			i;

	i = -1;
	if (!argument->arg)
		return (-1);
	len = (ssize_t)fpf_strlen(argument->arg);
	padding = 0;
	if (argument->flags[0] > -1 && argument->flags[0] < len)
		len = argument->flags[0];
	if (argument->flags[1] > len)
		padding = argument->flags[1] - len;
	if (argument->flags[4] == 0 && argument->flags[3] == 0)
		fpf_nputchar(' ', padding, argument);
	if (argument->flags[3] == 1 && argument->flags[4] == 0)
		fpf_nputchar('0', padding, argument);
	fpf_buff(argument->arg, argument);
	if (argument->flags[4] == 1)
		fpf_nputchar(' ', padding, argument);
	if (argument->spec == 'C' || argument->spec == 'S')
		free(argument->arg);
	return (0);
}
