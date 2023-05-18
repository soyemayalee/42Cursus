/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:15:00 by solee2            #+#    #+#             */
/*   Updated: 2022/11/29 19:46:06 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*element;

	if (!lst)
		return (0);
	else
	{
		list = 0;
		while (lst)
		{
			element = ft_lstnew(f(lst->content));
			if (!element)
			{
				ft_lstclear(&list, del);
				return (0);
			}
			ft_lstadd_back(&list, element);
			lst = lst->next;
		}
	}
	return (list);
}
