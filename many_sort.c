/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:54:46 by solee2            #+#    #+#             */
/*   Updated: 2023/05/16 16:39:09 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_bit_size(t_list **input)
{
	t_list	*temp;
	int		max;
	int		bit;

	temp = *input;
	max = temp->index;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	bit = 0;
	while (max >> bit != 0)
		bit++;
	return (bit);
}

void	sort_process(t_list **one, t_list **two, int j)
{
	t_list	*temp;
	int		a_size;
	int		i;

	i = 0;
	a_size = ft_lstsize(*one);
	while (i < a_size)
	{
		temp = *one;
		if (((temp->index >> j) & 1) != 1)
			push_pa_pb(one, two, "pb");
		else if (((temp->index >> j) & 1) == 1 && ft_lstsize(*one) != 1)
			rotate_ra_rb(one, "ra");
		temp = temp->next;
		i++;
	}
}

void	many_sort(t_list **one, t_list **two)
{
	int		bit;
	int		j;
	int		b_size;

	bit = get_bit_size(one);
	j = 0;
	while (j < bit)
	{
		sort_process(one, two, j);
		b_size = ft_lstsize(*two);
		while (b_size > 0)
		{
			push_pa_pb(one, two, "pa");
			b_size--;
		}
		j++;
	}
}
