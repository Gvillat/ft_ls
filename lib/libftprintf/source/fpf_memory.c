/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 17:35:38 by gvillat           #+#    #+#             */
/*   Updated: 2016/09/27 17:35:40 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fpf_printf.h"

PF		*fpf_init_argument(PF *argument)
{
	int i;

	i = 0;
	while (i < 13)
	{
		argument->flags[i] = 0;
		i++;
	}
	argument->flags[0] = -1;
	argument->flags[1] = -1;
	argument->format = NULL;
	argument->index = 0;
	argument->spec = ' ';
	argument->arg = NULL;
	argument->warg = NULL;
	return (argument);
}

void	fpf_init_spe_tab(SPE *spe)
{
	int i;

	i = 0;
	while (i < 128)
		spe->spe[i++] = fpf_arg_nospe;
	spe->spe['p'] = pointer_handler;
	spe->spe['s'] = string_handler;
	spe->spe['S'] = string_handler;
	spe->spe['c'] = character_handler;
	spe->spe['C'] = character_handler;
	spe->spe['d'] = signed_handler;
	spe->spe['D'] = signed_handler;
	spe->spe['i'] = signed_handler;
	spe->spe['o'] = unsigned_handler;
	spe->spe['O'] = unsigned_handler;
	spe->spe['u'] = unsigned_handler;
	spe->spe['U'] = unsigned_handler;
	spe->spe['%'] = prc_handler;
	spe->spe['x'] = unsigned_handler;
	spe->spe['X'] = unsigned_handler;
	spe->spe['b'] = unsigned_handler;
}

void	fpf_init_buff(void)
{
	int n;

	n = 0;
	while (n < BUFF_MAX)
	{
		g_buff[n] = '\0';
		n++;
	}
	g_i = 0;
}

int		fpf_check_spec_bis(PF *argument)
{
	if (argument->format[argument->index] == 'c')
		argument->spec = 'c';
	else if (argument->format[argument->index] == 'C')
		argument->spec = 'C';
	else if (argument->format[argument->index] == 'F')
		argument->spec = 'F';
	else if (argument->format[argument->index] == 'f')
		argument->spec = 'f';
	else
		argument->spec = argument->format[argument->index];
	return (argument->index);
}
