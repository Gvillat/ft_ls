/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:54:09 by gvillat           #+#    #+#             */
/*   Updated: 2015/12/01 18:22:46 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fpf_printf.h"

int	fpf_strcmp(const char *s1, const char *s2)
{
	if (*s1 != *s2 || (*s1 == '\0' && *s2 == '\0'))
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (fpf_strcmp(s1 + 1, s2 + 1));
}
