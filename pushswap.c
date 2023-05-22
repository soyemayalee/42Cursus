/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:55:59 by solee2            #+#    #+#             */
/*   Updated: 2023/05/22 11:32:47 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	index_stack(t_list **stack)
{
	t_list	*head;
	int		i;

	i = 0;
	head = next_minimum(stack);
	while (head)
	{
		head->index = i;
		i = i + 1;
		head = next_minimum(stack);
	}
}

static void	set_stack(t_list **stack, int argc, char **argv)
{
	t_list		*new;
	char		**numbers;
	long long	temp;
	int			i;

	i = 0;
	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else
	{
		numbers = argv;
		i = 1;
	}
	while (numbers[i])
	{
		temp = atoi_long_long(numbers[i]);
		new = ft_lstnew(temp);
		ft_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
		ft_free(numbers);
}

int	sort_check_stack(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp && temp->next != NULL)
	{
		if (temp->number >= temp->next->number)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	sort_stack(t_list **one, t_list **two)
{
	if (ft_lstsize(*one) <= 5)
		few_sort(one, two);
	else
		many_sort(one, two);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (0);
	arg_check(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	if (!stack_a)
		return (0);
	stack_b = (t_list **)malloc(sizeof(t_list));
	if (!stack_b)
	{
		free(stack_a);
		return (0);
	}
	*stack_a = NULL;
	*stack_b = NULL;
	set_stack(stack_a, argc, argv);
	if (sort_check_stack(stack_a) != 0)
		sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
