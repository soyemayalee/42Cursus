/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:36:03 by solee2            #+#    #+#             */
/*   Updated: 2023/10/25 20:24:08 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	one_usleep(useconds_t time)
{
	long int	start;

	start = get_time();
	while ((get_time() - start) < time)
	{
		usleep(time / 10);
	}
	return (0);
}

void	*one_action(void *pointer)
{
	t_philo	*philo;
	int		death;

	philo = (t_philo *)pointer;
	philo->time_to_die = philo->info->time_death + get_time();
	death = get_death(philo);
	while (death == 0)
	{
		pthread_mutex_lock(philo->fork_left);
		print_message(FORK_LEFT, philo);
		pthread_mutex_lock(&philo->info->lock);
		one_usleep(philo->info->time_death);
		philo->info->death = 1;
		pthread_mutex_unlock(&philo->info->lock);
		pthread_mutex_unlock(philo->fork_left);
		death = get_death(philo);
	}
	if (death == 1)
		one_print_message(DEATH, philo);
	return ((void *)0);
}

int	one_philosopher(t_info *info)
{
	int	death;

	info->time_start = get_time();
	if (pthread_create(&info->tid[0], NULL, &one_action, \
	&info->philosophers[0]))
		return (print_error("ERROR) Error Creating Threads", info), ERROR);
	pthread_mutex_lock(&info->lock);
	death = info->death;
	pthread_mutex_unlock(&info->lock);
	while (death == 0)
	{
		pthread_mutex_lock(&info->lock);
		death = info->death;
		pthread_mutex_unlock(&info->lock);
		one_usleep(1);
	}
	if (pthread_join(info->tid[0], NULL))
		return (ERROR);
	free_info(info);
	return (0);
}
