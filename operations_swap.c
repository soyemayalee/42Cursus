/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:55:33 by solee2            #+#    #+#             */
/*   Updated: 2023/05/15 19:33:39 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_operation(t_list **input)
{
	t_list	*temp;
	t_list	*next;
	int		number;
	int		index;

	temp = *input;
	next = temp->next;
	if (!temp && !next)
	{
		fd_message("ERROR");
		return ;
	}
	number = temp->number;
	index = temp->index;
	temp->number = next->number;
	temp->index = next->index;
	next->number = number;
	next->index = index;
}

void	swap_sa_sb(t_list **input, char *operation)
{
	if (ft_streq(SA, operation) != 1)
	{
		swap_operation(input);
		fd_message("sa");
	}
	else if (ft_streq(SB, operation) != 1)
	{
		swap_operation(input);
		fd_message("sb");
	}
}

void	swap_ss(t_list **one, t_list **two)
{
	int	size_one;
	int	size_two;

	size_one = ft_lstsize(*one);
	size_two = ft_lstsize(*two);
	if (size_one < 2 || size_two < 2)
	{
		fd_message("ERROR");
		return ;
	}
	swap_operation(one);
	swap_operation(two);
	fd_message("ss");
}
