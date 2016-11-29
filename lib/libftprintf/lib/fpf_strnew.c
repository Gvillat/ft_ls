/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 20:01:28 by gvillat           #+#    #+#             */
/*   Updated: 2015/12/15 17:35:48 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "../includes/fpf_printf.h"

char	*fpf_strnew(size_t size)
{
	char	*text;

	text = (char *)malloc((size + 1) * sizeof(char));
	if (!text)
		return (NULL);
	fpf_memset(text, '\0', size + 1);
	return (text);
}
