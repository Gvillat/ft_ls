/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_strdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 05:38:39 by gvillat           #+#    #+#             */
/*   Updated: 2016/12/15 05:38:40 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fpf_printf.h"

char	*fpf_strdup(const char *s1)
{
	char	*cp;

	cp = (char *)malloc(sizeof(char) * (fpf_strlen(s1) + 1));
	if (!cp)
		return (NULL);
	fpf_strcpy(cp, s1);
	return (cp);
}
