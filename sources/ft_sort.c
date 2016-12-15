/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 03:09:21 by gvillat           #+#    #+#             */
/*   Updated: 2016/12/15 03:09:22 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		sort_alpha(char *one, char *two)
{
	return (ft_strcmp(one, two) > 0 ? 1 : 0);
}

int		sort_ralpha(char *one, char *two)
{
	return (ft_strcmp(one, two) < 0 ? 1 : 0);
}

int		sort_time(char *one, char *two, char *path)
{
	STAT st1;
	STAT st2;
	char *pathone;
	char *pathtwo;
	char *temp;

	temp = tool_checkdirname(path);
	pathone = ft_strjoin(temp, one);
	pathtwo = ft_strjoin(temp, two);
	ft_memdel((void*)&temp);
	lstat(pathone, &st1);
	lstat(pathtwo, &st2);
	ft_memdel((void*)&pathone);
	ft_memdel((void*)&pathtwo);
	return (st1.st_mtime < st2.st_mtime);
}

int		sort_rtime(char *one, char *two, char *path)
{
	STAT st1;
	STAT st2;
	char *pathone;
	char *pathtwo;
	char *temp;

	temp = tool_checkdirname(path);
	pathone = ft_strjoin(temp, one);
	pathtwo = ft_strjoin(temp, two);
	ft_memdel((void*)&temp);
	lstat(pathone, &st1);
	lstat(pathtwo, &st2);
	ft_memdel((void*)&pathone);
	ft_memdel((void*)&pathtwo);
	return (st1.st_mtime > st2.st_mtime);
}

void	swap(void **one, void **two)
{
	void *temp;

	temp = *one;
	*one = *two;
	*two = temp;
}
