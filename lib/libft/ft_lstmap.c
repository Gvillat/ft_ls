/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:15:11 by gvillat           #+#    #+#             */
/*   Updated: 2015/12/03 20:25:48 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*current;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew(lst->content, lst->content_size);
	if (!new)
		return (NULL);
	new = (*f)(new);
	while (lst->next)
	{
		lst = lst->next;
		current = ft_lstnew(lst->content, lst->content_size);
		if (!current)
			return (NULL);
		ft_lstpush(new, (*f)(current));
	}
	return (new);
}
