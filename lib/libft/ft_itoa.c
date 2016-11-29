/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:20:55 by gvillat           #+#    #+#             */
/*   Updated: 2015/12/03 18:52:33 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_itoa(int n)
{
	int		nbr;
	int		size;
	char	*str;

	if (n == -2147483648 || n == 0)
		return (ft_strdup(!n ? "0" : "-2147483648"));
	nbr = n;
	size = ft_decade(nbr);
	str = ft_strnew(size + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		ft_pushchar(str, '-');
		n = -n;
	}
	nbr = ft_power(10, size - 1);
	while (nbr > 0)
	{
		str = ft_pushchar(str, (n / nbr) + 48);
		n = n % nbr;
		nbr = nbr / 10;
	}
	return (str);
}
