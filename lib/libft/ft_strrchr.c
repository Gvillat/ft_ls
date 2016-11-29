/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:34:56 by gvillat           #+#    #+#             */
/*   Updated: 2015/11/29 16:06:55 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int len;

	len = ft_strlen((char*)s);
	s += len;
	while (len > -1)
	{
		if (*s == c)
			return ((char*)s);
		len--;
		s--;
	}
	return (NULL);
}
