/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 19:55:50 by gvillat           #+#    #+#             */
/*   Updated: 2015/12/16 21:53:02 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/fpf_printf.h"

char		*fpf_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = fpf_strnew(len);
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

char		*fpf_wstrsub(wchar_t *ws, unsigned int start, size_t len)
{
	int		real_len;
	int		i;
	char	*fresh;

	real_len = 0;
	i = 0;
	while (ws[i] != '\0' && (int)len >= fpf_wcharlen(ws[i]))
	{
		len -= fpf_wcharlen(ws[i]);
		real_len += fpf_wcharlen(ws[i]);
		i++;
	}
	fresh = fpf_transform_wchar_in_char(ws);
	return (fpf_strsub_with_free(fresh, start, real_len));
}

char		*fpf_strsub_with_free(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	char	*tmp;
	int		i;

	tmp = NULL;
	if (!s)
		return (NULL);
	tmp = (char*)s;
	fresh = malloc((len + 1) * sizeof(char));
	i = 0;
	if (!fresh)
		return (NULL);
	fresh[len] = '\0';
	while (len > 0)
	{
		fresh[i] = s[start];
		i++;
		start++;
		len--;
	}
	free(tmp);
	return (fresh);
}
