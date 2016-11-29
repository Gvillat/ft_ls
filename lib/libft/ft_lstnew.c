/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:15:18 by gvillat           #+#    #+#             */
/*   Updated: 2015/12/03 20:26:28 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *ret;

	ret = ft_memalloc(sizeof(t_list));
	if (!ret)
		return (NULL);
	if (!content)
	{
		ret->content = NULL;
		ret->content_size = 0;
		return (ret);
	}
	ret->content_size = content_size;
	ret->content = ft_memalloc(content_size);
	if (!ret->content)
		ret->content = NULL;
	else
		ret->content = ft_memcpy(ret->content, content, content_size);
	return (ret);
}
