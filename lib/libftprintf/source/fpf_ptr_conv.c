/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_ptr_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 17:35:46 by gvillat           #+#    #+#             */
/*   Updated: 2016/09/27 17:35:47 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fpf_printf.h"

int		pointer_handler(PF *argument, va_list ap)
{
	uintmax_t	n;

	n = va_arg(ap, uintmax_t);
	if (!(argument->arg = fpf_strlower(fpf_itoa_base(n, 16))))
		return (-1);
	return (fpf_print_number(argument, "0x"));
}

int		prc_handler(PF *argument, va_list ap)
{
	argument->arg = "%";
	fpf_print_character(argument);
	return ((int)ap);
}
