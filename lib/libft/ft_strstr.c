/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:40:01 by gvillat           #+#    #+#             */
/*   Updated: 2015/11/29 16:29:57 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;

	if (!*little)
		return ((char*)big);
	i = 0;
	j = 0;
	while (big[i])
	{
		while (little[j] && big[i + j] == little[j])
			j++;
		if (!little[j])
			return ((char*)(big + i));
		j = 0;
		i++;
	}
	return (NULL);
}
