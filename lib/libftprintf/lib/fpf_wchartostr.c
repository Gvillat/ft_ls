/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_wchartostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 17:36:40 by gvillat           #+#    #+#             */
/*   Updated: 2016/09/27 17:36:41 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fpf_printf.h"

static int		fpf_wchartostr_bis(char *s, wchar_t wc)
{
	if (wc < 0x800)
	{
		*(s++) = ((wc >> 6) & 0x1F) | 0xC0;
		*(s++) = ((wc >> 0) & 0x3F) | 0x80;
		return (2);
	}
	else if (wc < 0x10000)
	{
		*(s++) = ((wc >> 12) & 0xF) | 0xE0;
		*(s++) = ((wc >> 6) & 0x3F) | 0x80;
		*(s++) = ((wc >> 0) & 0x3F) | 0x80;
		return (3);
	}
	else if (wc < 0x110000)
	{
		*(s++) = ((wc >> 18) & 0x7) | 0xF0;
		*(s++) = ((wc >> 12) & 0x3F) | 0x80;
		*(s++) = ((wc >> 6) & 0x3F) | 0x80;
		*(s++) = ((wc >> 0) & 0x3F) | 0x80;
		return (4);
	}
	return (0);
}

int				fpf_wchartostr(char *s, wchar_t wc)
{
	if (wc < 0x80)
	{
		*s = ((wc & 0x7F) | 0);
		return (1);
	}
	return (fpf_wchartostr_bis(s, wc));
}
