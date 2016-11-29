/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:09:37 by gvillat           #+#    #+#             */
/*   Updated: 2015/12/16 21:20:40 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char *pdst;

	pdst = dst;
	while (*src)
		*pdst++ = *src++;
	*pdst = '\0';
	return (dst);
}
