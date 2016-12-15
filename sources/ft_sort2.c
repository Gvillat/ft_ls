/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 03:11:10 by gvillat           #+#    #+#             */
/*   Updated: 2016/12/15 03:11:14 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_choose_sort(char *s1, char *s2, char *path)
{
	if (g_opt_r)
		return (sort_rtime(s1, s2, path));
	else
		return (sort_time(s1, s2, path));
}

int		ft_choose_sort_alpha(char *s1, char *s2)
{
	if (g_opt_r)
		return (sort_ralpha(s1, s2));
	else
		return (sort_alpha(s1, s2));
}

int		ft_sort_args(LD **curr)
{
	static LD	*head = NULL;
	LD			*tmp;

	if (!head)
		head = *curr;
	if (!(tmp = *curr) || !(*curr)->next)
	{
		head = NULL;
		return (1);
	}
	while (1)
	{
		if (ft_choose_sort_alpha(tmp->path, tmp->next->path))
		{
			swap((void **)&tmp->name, (void **)&tmp->next->name);
			swap((void **)&tmp->path, (void **)&tmp->next->path);
			swap((void **)&tmp->file, (void **)&tmp->next->file);
			swap((void **)&tmp->size, (void **)&tmp->next->size);
			if (tmp != head)
				return (0);
		}
		if (ft_sort_args(&tmp->next))
			return (1);
	}
}

int		ft_sort_time(LF **curr, char *path)
{
	static LF	*head = NULL;
	LF			*tmp;

	if (!head)
		head = *curr;
	if (!(tmp = *curr) || !(*curr)->next)
	{
		head = NULL;
		return (1);
	}
	while (1)
	{
		if (ft_choose_sort(tmp->name, tmp->next->name, path))
		{
			swap((void**)&tmp->name, (void**)&tmp->next->name);
			if (tmp != head)
				return (0);
		}
		if (ft_sort_time(&tmp->next, path))
			return (1);
	}
}

int		ft_sort(LF **curr)
{
	static LF	*head = NULL;
	LF			*tmp;

	if (!head)
		head = *curr;
	if (!(tmp = *curr) || !(*curr)->next)
	{
		head = NULL;
		return (1);
	}
	while (1)
	{
		if (ft_choose_sort_alpha(tmp->name, tmp->next->name))
		{
			swap((void**)&tmp->name, (void**)&tmp->next->name);
			if (tmp != head)
				return (0);
		}
		if (ft_sort(&tmp->next))
			return (1);
	}
}
