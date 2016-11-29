/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 19:56:27 by gvillat           #+#    #+#             */
/*   Updated: 2015/12/16 21:41:20 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		len;
	int		j;
	char	**tab;

	tab = ft_memalloc(sizeof(tab) * (ft_countwords(s, c) + 1));
	i = 0;
	len = 0;
	j = 0;
	if (!tab)
		return (NULL);
	while (s[i])
	{
		while (s[i + len] && s[i + len] != c)
			len++;
		if (len)
			tab[j++] = ft_strsub(s, i, len);
		i += len ? len : 1;
		len = 0;
	}
	tab[j] = NULL;
	return (tab);
}
