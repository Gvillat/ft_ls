/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 12:39:45 by gvillat           #+#    #+#             */
/*   Updated: 2015/12/01 17:10:59 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strnew(ft_strlen(s));
	if (!str)
		return (NULL);
	while (*s)
	{
		str[i++] = (*f)(*(s++));
	}
	return (str);
}
