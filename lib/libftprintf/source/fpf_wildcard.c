/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_wildcard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:28:33 by gvillat           #+#    #+#             */
/*   Updated: 2016/11/07 13:28:35 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fpf_printf.h"

int			fpf_wildcard(PF *argument, va_list ap, int i)
{
	if (argument->format[argument->index] == '*')
	{
		argument->flags[i] = va_arg(ap, int);
		if (argument->flags[i] < 0)
		{
			if (i == 1)
			{
				argument->flags[4] = 1;
				argument->flags[1] *= -1;
			}
			else if (i == 0)
			{
				argument->flags[0] = -1;
				argument->index++;
				return (0);
			}
		}
		argument->index++;
	}
	return (1);
}
