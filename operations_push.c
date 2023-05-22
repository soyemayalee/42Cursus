/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:54:59 by solee2            #+#    #+#             */
/*   Updated: 2023/05/15 19:32:14 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	push_operation(t_list **origin, t_list **destination)
{
	t_list	*temp;
	t_list	*head_origin;
	t_list	*head_destination;

	head_origin = *origin;
	head_destination = *destination;
	temp = head_origin;
	*origin = head_origin->next;
	if (!head_destination)
	{
		head_destination = temp;
		head_destination->next = NULL;
		*destination = head_destination;
	}
	else
	{
		temp->next = head_destination;
		*destination = temp;
	}
	return (0);
}

int	push_pa_pb(t_list **one, t_list **two, char *operation)
{
	if (ft_streq(PA, operation) != 1)
	{
		if (push_operation(two, one) == 1)
			fd_message("ERROR - PA");
		else
		{
			fd_message("pa");
			return (0);
		}
	}
	else if (ft_streq(PB, operation) != 1)
	{
		if (push_operation(one, two) == 1)
			fd_message("ERROR - PB");
		else
		{
			fd_message("pb");
			return (0);
		}
	}
	return (0);
}
