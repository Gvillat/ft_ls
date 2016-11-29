/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_unsigned_conv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 17:36:02 by gvillat           #+#    #+#             */
/*   Updated: 2016/09/27 17:36:03 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fpf_printf.h"

static uintmax_t		unsigned_cast(PF *argument, va_list ap)
{
	uintmax_t			n;

	n = va_arg(ap, uintmax_t);
	if (argument->flags[7] == 1)
		n = (unsigned char)(n);
	else if (argument->flags[8] == 1)
		n = (unsigned short)(n);
	else if (argument->flags[10] == 1)
		n = (unsigned long)(n);
	else if (argument->flags[9] == 1)
		n = (unsigned long long)(n);
	else if (argument->flags[11] == 1)
		n = (uintmax_t)(n);
	else if (argument->flags[12] == 1)
		n = (size_t)(n);
	else
		n = (unsigned int)(n);
	return (n);
}

static int				unsigned_helper(PF *argument)
{
	ssize_t				len;
	int					nullstr;

	if (!argument->arg)
		return (-1);
	len = (ssize_t)fpf_strlen(argument->arg);
	nullstr = (len == 1 && argument->arg[0] == '0') ? 0 : 1;
	if (argument->flags[2] == 1)
	{
		if (argument->spec == 'o' || argument->spec == 'O')
		{
			if (argument->flags[0] <= len && argument->arg[0] != '0')
				argument->flags[0] = len + 1;
		}
		else if (argument->spec == 'x' && nullstr != 0)
			return (fpf_print_number(argument, "0x"));
		else if (argument->spec == 'X' && nullstr != 0)
			return (fpf_print_number(argument, "0X"));
	}
	return (fpf_print_number(argument, ""));
}

int						unsigned_handler(PF *argument, va_list ap)
{
	uintmax_t			n;

	if (argument->spec == 'x' || argument->spec == 'X'
		|| argument->spec == 'u' || argument->spec == 'o'
		|| argument->spec == 'b')
		n = unsigned_cast(argument, ap);
	else
		n = (unsigned long int)va_arg(ap, uintmax_t);
	if (argument->spec == 'o' || argument->spec == 'O')
		argument->arg = fpf_itoa_base(n, 8);
	else if (argument->spec == 'u' || argument->spec == 'U')
		argument->arg = fpf_itoa_base(n, 10);
	else if (argument->spec == 'x')
		argument->arg = fpf_strlower(fpf_itoa_base(n, 16));
	else if (argument->spec == 'b')
		argument->arg = fpf_itoa_base(n, 2);
	else
		argument->arg = fpf_itoa_base(n, 16);
	return (unsigned_helper(argument));
}
