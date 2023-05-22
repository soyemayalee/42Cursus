/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:55:21 by solee2            #+#    #+#             */
/*   Updated: 2023/05/16 16:27:08 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	rotate_operation(t_list **input)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*input) < 2)
		return (1);
	head = *input;
	tail = ft_lstlast(head);
	tail->next = head;
	*input = head->next;
	head->next = NULL;
	return (0);
}

int	rotate_ra_rb(t_list **input, char *operation)
{
	if (ft_streq(RA, operation) != 1)
	{
		if (rotate_operation(input) == 1)
			fd_message("ERROR - RA");
		else
			fd_message("ra");
	}
	else if (ft_streq(RB, operation) != 1)
	{
		if (rotate_operation(input) == 1)
			fd_message("ERROR - Rb");
		else
			fd_message("rb");
	}
	return (0);
}

int	rotate_rr(t_list **one, t_list **two)
{
	int	size_one;
	int	size_two;

	size_one = ft_lstsize(*one);
	size_two = ft_lstsize(*two);
	if (size_one < 2 || size_two < 2)
		return (1);
	if (rotate_operation(one) == 1)
		fd_message("ERROR - RR");
	if (rotate_operation(two) == 1)
		fd_message("ERROR - RR");
	fd_message("rr");
	return (0);
}
