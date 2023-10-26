/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:35:54 by solee2            #+#    #+#             */
/*   Updated: 2023/10/26 00:56:42 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	many_hold_fork(t_philo *philo)
{
	usleep(300);
	while (philo->fork_left->__data.__lock == 1 || \
	philo->fork_right->__data.__lock == 1)
	{
		if (get_time() >= philo->time_to_die)
		{
			print_message(DEATH, philo);
		}
		usleep(50);
	}
	pthread_mutex_lock(philo->fork_left);
	pthread_mutex_lock(philo->fork_right);
	print_message(FORK_LEFT, philo);
	print_message(FORK_RIGHT, philo);
}

void	many_eat_sleep_think(t_philo *philo)
{
	many_hold_fork(philo);
	philo->time_to_die = get_time() + philo->info->time_death;
	print_message(EAT, philo);
	philo->count_eat++;
	if (philo->count_eat == philo->info->num_meals)
		update_info(philo);
	ft_usleep(philo, philo->time_eat);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
	print_message(SLEEP, philo);
	ft_usleep(philo, philo->time_sleep);
	print_message(THINK, philo);
	if (philo->time_eat > philo->time_sleep)
		ft_usleep(philo, philo->time_eat - philo->time_sleep);
}

void	*many_action_set(void *pointer)
{
	t_philo	*philos;

	philos = (t_philo *)pointer;
	philos->time_to_die = philos->info->time_death + get_time();
	if (philos->id % 2 == 1)
		usleep(philos->info->time_eat * 100);
	while (get_terminate(philos) == 0)
		many_eat_sleep_think(philos);
	return ((void *)0);
}

int	many_philosophers(t_info *info)
{
	int	i;

	i = 0;
	info->time_start = get_time();
	while (i < info->num_philo)
	{
		if (pthread_create(&info->tid[i], NULL, &many_action_set, \
		&info->philosophers[i]))
			return (print_error("ERROR) Error Creating Threads", info), ERROR);
		i++;
	}
	i = 0;
	while (i < info->num_philo)
	{
		if (pthread_join(info->tid[i], NULL))
			return (print_error("ERROR) Error Joining Threads", info), ERROR);
		i++;
	}
	return (0);
}
