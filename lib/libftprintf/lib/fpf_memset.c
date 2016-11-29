/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:04:51 by gvillat           #+#    #+#             */
/*   Updated: 2015/11/29 16:04:44 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fpf_printf.h"

void	*fpf_memset(void *dest, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest1;
	unsigned char	c1;

	i = 0;
	dest1 = dest;
	c1 = c;
	while (i < n)
		dest1[i++] = c1;
	return (dest);
}
