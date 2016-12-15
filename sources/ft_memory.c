/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 05:21:11 by gvillat           #+#    #+#             */
/*   Updated: 2016/12/15 05:21:19 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

LD	*ft_create_dir(char *name)
{
	LD *new;

	if (!(new = (LD*)malloc(sizeof(LD))))
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->path = name;
	new->name = ft_strdup(name);
	new->file = NULL;
	new->size = 0;
	return (new);
}

LD	*ft_add_next_dir(char *name, LD **curr)
{
	LD		*tmp;
	char	*str;

	if (!*curr)
		return (*curr = ft_create_dir(name));
	str = tool_checkdirname((*curr)->path);
	if ((*curr)->next)
	{
		tmp = ft_create_dir(name);
		tmp->path = ft_strjoin(str, tmp->name);
		tmp->prev = *curr;
		tmp->next = (*curr)->next;
		(*curr)->next->prev = tmp;
		(*curr)->next = tmp;
	}
	else
	{
		tmp = *curr;
		tmp->next = ft_create_dir(name);
		tmp->next->path = ft_strjoin(str, tmp->next->path);
		tmp->next->prev = tmp;
	}
	ft_memdel((void**)&str);
	return (*curr);
}

LF	*ft_create_file(char *name)
{
	LF *new;

	if (!(new = (LF*)malloc(sizeof(LF))))
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->name = ft_strdup(name);
	new->info = NULL;
	return (new);
}

LD	*ft_add_begin_dir(char *name, LD **curr)
{
	LD *tmp;

	if (!*curr)
	{
		*curr = ft_create_dir(name);
		tmp = *curr;
		tmp->path = ft_strdup(name);
		return (*curr);
	}
	tmp = *curr;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_create_dir(name);
	tmp->next->path = ft_strdup(name);
	tmp->next->prev = tmp;
	return (tmp->next);
}

LF	*ft_add_end_file(char *name, LF **curr)
{
	LF *tmp;

	if (!*curr)
		return (*curr = ft_create_file(name));
	tmp = *curr;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_create_file(name);
	tmp->next->prev = tmp;
	return ((*curr)->next);
}
