/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   few_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:54:23 by solee2            #+#    #+#             */
/*   Updated: 2023/05/15 19:29:21 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_three(t_list **input)
{
	t_list		*first;
	long long	one;
	long long	two;
	long long	three;

	first = *input;
	one = first->number;
	two = first->next->number;
	three = first->next->next->number;
	if (three > one && three > two && one > two)
		swap_sa_sb(input, "sa");
	else if (one > two && one > three && two > three)
	{
		swap_sa_sb(input, "sa");
		reverse_rotate_rra_rrb(input, "rra");
	}
	else if (one > two && one > three && three > two)
		rotate_ra_rb(input, "ra");
	else if (two > one && two > three && three > one)
	{
		swap_sa_sb(input, "sa");
		rotate_ra_rb(input, "ra");
	}
	else if (two > one && two > three && one > three)
		reverse_rotate_rra_rrb(input, "rra");
}

int	minimum_location(t_list **input)
{
	t_list	*temp;
	int		min;
	int		count;
	int		i;

	count = 0;
	i = 0;
	temp = *input;
	min = temp->number;
	temp = temp->next;
	while (temp)
	{
		i++;
		if (temp->number < min)
		{
			min = temp->number;
			count = i;
		}
		temp = temp->next;
	}
	return (count);
}

void	sort_four(t_list **one, t_list **two)
{
	int	location;

	location = minimum_location(one);
	if (location == 1)
		rotate_ra_rb(one, "ra");
	else if (location == 2)
	{
		rotate_ra_rb(one, "ra");
		rotate_ra_rb(one, "ra");
	}
	else if (location == 3)
		reverse_rotate_rra_rrb(one, "rra");
	push_pa_pb(one, two, "pb");
	sort_three(one);
	push_pa_pb(one, two, "pa");
}

void	sort_five(t_list **one, t_list **two)
{
	int	location;

	location = minimum_location(one);
	if (location == 1)
		rotate_ra_rb(one, "ra");
	else if (location == 2)
	{
		rotate_ra_rb(one, "ra");
		rotate_ra_rb(one, "ra");
	}
	else if (location == 3)
	{
		reverse_rotate_rra_rrb(one, "rra");
		reverse_rotate_rra_rrb(one, "rra");
	}
	else if (location == 4)
		reverse_rotate_rra_rrb(one, "rra");
	push_pa_pb(one, two, "pb");
	sort_four(one, two);
	push_pa_pb(one, two, "pa");
}

void	few_sort(t_list **one, t_list **two)
{
	int	size;

	size = ft_lstsize(*one);
	if (size == 0 || size == 1)
		return ;
	if (size == 2)
		swap_sa_sb(one, "sa");
	if (size == 3)
		sort_three(one);
	else if (size == 4)
		sort_four(one, two);
	else if (size == 5)
		sort_five(one, two);
}
