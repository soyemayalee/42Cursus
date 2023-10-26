/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:08:56 by solee2            #+#    #+#             */
/*   Updated: 2023/10/25 20:24:08 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long int	get_time(void)
{
	struct timeval	time;
	long int		result;

	if (gettimeofday(&time, NULL))
		return (print_error("ERROR) Error Getting Time", NULL), ERROR);
	result = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (result);
}

int	get_death(t_philo *philo)
{
	int	death;

	pthread_mutex_lock(&philo->info->lock);
	death = philo->info->death;
	pthread_mutex_unlock(&philo->info->lock);
	return (death);
}

int	get_terminate(t_philo *philo)
{
	int	terminate;

	pthread_mutex_lock(&philo->info->lock);
	terminate = philo->info->terminate;
	pthread_mutex_unlock(&philo->info->lock);
	return (terminate);
}
