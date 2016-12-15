/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_strcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 05:38:23 by gvillat           #+#    #+#             */
/*   Updated: 2016/12/15 05:38:33 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fpf_printf.h"

int	fpf_strcmp(const char *s1, const char *s2)
{
	if (*s1 != *s2 || (*s1 == '\0' && *s2 == '\0'))
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (fpf_strcmp(s1 + 1, s2 + 1));
}
