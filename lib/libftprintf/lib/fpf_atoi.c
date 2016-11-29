/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:31:44 by gvillat           #+#    #+#             */
/*   Updated: 2015/12/16 22:24:56 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fpf_printf.h"

int	fpf_atoi(const char *nbr)
{
	int result;
	int neg;

	result = 0;
	neg = 0;
	while (*nbr == ' ' || fpf_isescaped(*nbr))
		nbr++;
	if (*nbr == '-' || *nbr == '+')
		neg = (*(nbr++) == '-') ? 1 : 0;
	while (*nbr && fpf_isdigit(*nbr))
		result = result * 10 + (*(nbr++) - 48);
	return (neg ? result * -1 : result);
}
