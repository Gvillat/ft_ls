/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:47:32 by gvillat           #+#    #+#             */
/*   Updated: 2015/12/03 20:04:21 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	d;
	unsigned char	*s2;
	int				i;

	i = 0;
	s2 = (unsigned char *)s;
	d = c;
	while (n--)
	{
		if (s2[i] == d)
			return (&(s2[i]));
		i++;
	}
	return (NULL);
}
