/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:55:12 by solee2            #+#    #+#             */
/*   Updated: 2023/05/15 19:32:29 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	reverse_rotate_operation(t_list **input)
{
	t_list	*head;
	t_list	*tail;
	int		state;

	if (ft_lstsize(*input) < 2)
		return (1);
	head = *input;
	tail = ft_lstlast(head);
	state = 0;
	while (head && state == 0)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			state = 1;
		}
		else
			head = head->next;
	}
	tail->next = *input;
	*input = tail;
	return (0);
}

int	reverse_rotate_rra_rrb(t_list **input, char *operation)
{
	if (ft_streq(RRA, operation) != 1)
	{
		if (reverse_rotate_operation(input) == 1)
			fd_message("ERROR - RRA");
		else
			fd_message("rra");
	}
	else if (ft_streq(RRB, operation) != 1)
	{
		if (reverse_rotate_operation(input) == 1)
			fd_message("ERROR - RRB");
		else
			fd_message("rrb");
	}
	return (0);
}

int	reverse_rotate_rrr(t_list **one, t_list **two)
{
	int	size_one;
	int	size_two;

	size_one = ft_lstsize(*one);
	size_two = ft_lstsize(*two);
	if (size_one < 2 || size_two < 2)
		return (1);
	if (reverse_rotate_operation(one) == 1)
		fd_message("ERROR - RRR");
	if (reverse_rotate_operation(two) == 1)
		fd_message("ERROR - RRR");
	fd_message("rrr");
	return (0);
}
