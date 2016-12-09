/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 17:36:25 by gvillat           #+#    #+#             */
/*   Updated: 2016/09/27 17:36:26 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fpf_printf.h"
#include <stdint.h>

// char	*fpf_itoa_base(uintmax_t nbr, int base)
// {
// 	static char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
// 	'A', 'B', 'C', 'D', 'E', 'F'};
// 	uintmax_t	n;
// 	intmax_t	i;
// 	int			converted_nbr[64];
// 	char		*str;

// 	if (nbr == 0)
// 		return ("0");
// 	i = 0;
// 	n = (intmax_t)nbr;
// 	while (n > 0)
// 	{
// 		converted_nbr[i++] = n % base;
// 		n /= base;
// 	}
// 	if (!(str = (char*)malloc(sizeof(char *) * i)))
// 		return (NULL);
// 	str[i + 1] = '\0';
// 	while (i >= 0)
// 		str[n++] = hex[converted_nbr[i--]];
// 	return (str);
// }

char	*fpf_itoa_base(uintmax_t a, int base)
{
	static char	basec[16] = "0123456789ABCDEF";
	char	*res;
	int		b;
	int		i;

	i = 0;
	b = a;
	if (base == 0)
		return (NULL);
	while (a != 0)
	{
		a = a / base;
		i++;
	}
	res = (char *)malloc(sizeof(char) * i + 1);
	if (b == 0)
	{
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	res[i] = '\0';
	i--;
	while (b != 0)
	{
		res[i] = basec[b % base];
		b = b / base;
		i--;
	}
	return (res);
}