/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 19:45:02 by gvillat           #+#    #+#             */
/*   Updated: 2015/12/03 20:04:55 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../../includes/libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*save_s1;
	char	*save_s2;

	save_s1 = (char *)s1;
	save_s2 = (char *)s2;
	while (n != 0 && (unsigned char)*save_s1 == (unsigned char)*save_s2)
	{
		n--;
		save_s1++;
		save_s2++;
	}
	if (n == 0)
		return (0);
	else
		return ((unsigned char)*save_s1 - (unsigned char)*save_s2);
}
