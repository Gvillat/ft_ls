/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 18:10:34 by gvillat           #+#    #+#             */
/*   Updated: 2016/10/24 18:10:35 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fpf_printf.h"

int			fpf_wcharlen(wchar_t wchar)
{
	if (wchar <= 0x7f)
		return (1);
	else if (wchar <= 0x7ff)
		return (2);
	else if (wchar <= 0xffff)
		return (3);
	else
		return (4);
}

size_t		fpf_wbytelen(wchar_t *ws)
{
	size_t	len;
	size_t	bytelen;

	len = fpf_wstrlen(ws);
	bytelen = 0;
	while (len > 0)
	{
		bytelen += fpf_wcharlen(*ws);
		ws++;
		len--;
	}
	return (bytelen);
}
