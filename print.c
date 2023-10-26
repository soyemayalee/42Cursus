/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:04:47 by solee2            #+#    #+#             */
/*   Updated: 2023/10/25 20:24:08 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	one_print_message(char *message, t_philo *philo)
{
	long int	time;

	pthread_mutex_lock(&philo->info->lock);
	pthread_mutex_lock(&philo->info->print);
	time = get_time() - philo->info->time_start;
	if (ft_strcmp(DEATH, message) == 0)
	{
		printf("%lu %d %s\n", time, philo->id, message);
		philo->info->death = 1;
		philo->info->terminate = 1;
	}
	if (!philo->info->death)
	{
		if (philo->info->terminate == 0)
			printf("%lu %d %s\n", time, philo->id, message);
	}
	pthread_mutex_unlock(&philo->info->print);
	pthread_mutex_unlock(&philo->info->lock);
}

void	print_message(char *message, t_philo *philo)
{
	long int	time;

	pthread_mutex_lock(&philo->info->lock);
	time = get_time() - philo->info->time_start;
	if (ft_strcmp(DEATH, message) == 0)
	{
		if (philo->info->terminate == 0)
			printf("%lu %d %s\n", time, philo->id, message);
		philo->info->terminate = 1;
	}
	if (!philo->info->death)
	{
		if (philo->info->terminate == 0)
			printf("%lu %d %s\n", time, philo->id, message);
	}
	pthread_mutex_unlock(&philo->info->lock);
}
