/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_nputchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 17:36:29 by gvillat           #+#    #+#             */
/*   Updated: 2016/09/27 17:36:31 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fpf_printf.h"

void		fpf_nputchar(char c, ssize_t n, PF *argument)
{
	ssize_t	i;
	char	s[2];

	s[0] = c;
	s[1] = '\0';
	i = 0;
	while (i < n)
	{
		fpf_buff(s, argument);
		i++;
	}
}
