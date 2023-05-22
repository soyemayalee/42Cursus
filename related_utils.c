/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   related_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:38:38 by solee2            #+#    #+#             */
/*   Updated: 2023/05/15 19:42:15 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	fd_message(char *str)
{
	ft_putendl_fd(str, 1);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

t_list	*next_minimum(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		state;

	min = NULL;
	state = 0;
	head = *stack;
	while (head)
	{
		if (state == 0 || head->number < min->number)
		{
			if (head->index == -1)
			{
				min = head;
				state = 1;
			}
		}
		head = head->next;
	}
	return (min);
}

void	free_stack(t_list **stack)
{
	t_list	*temp;
	t_list	*next;

	next = *stack;
	while (next)
	{
		temp = next;
		next = next->next;
		free(temp);
	}
	free(stack);
}
