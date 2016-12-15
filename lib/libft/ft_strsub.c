/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 19:55:50 by gvillat           #+#    #+#             */
/*   Updated: 2015/12/16 21:53:02 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = ft_strnew(len);
	if (s2 == NULL || s == NULL)
		return (NULL);
	while (len--)
	{
		s2[i] = s[start];
		i++;
		start++;
	}
	return (s2);
}
