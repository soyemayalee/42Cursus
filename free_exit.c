/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:35:26 by solee2            #+#    #+#             */
/*   Updated: 2023/10/25 20:21:07 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	free_info(t_info *info)
{
	if (info->tid)
		free(info->tid);
	if (info->forks)
		free(info->forks);
	if (info->philosophers)
		free(info->philosophers);
}

void	destroy_free(t_info *info)
{
	int	i;

	i = 0;
	if (!info)
		return ;
	while (i < info->num_philo)
	{
		pthread_mutex_destroy(&info->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&info->print);
	pthread_mutex_destroy(&info->lock);
	free_info(info);
}

int	print_error(char *message, t_info *info)
{
	printf("%s\n", message);
	if (info)
		destroy_free(info);
	return (ERROR);
}
