/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 05:34:16 by gvillat           #+#    #+#             */
/*   Updated: 2016/12/15 05:34:18 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nbr)
{
	int result;
	int neg;

	result = 0;
	neg = 0;
	while (*nbr == ' ' || ft_isescaped(*nbr))
		nbr++;
	if (*nbr == '-' || *nbr == '+')
		neg = (*(nbr++) == '-') ? 1 : 0;
	while (*nbr && ft_isdigit(*nbr))
		result = result * 10 + (*(nbr++) - 48);
	return (neg ? result * -1 : result);
}
