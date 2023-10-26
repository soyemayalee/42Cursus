/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:35:36 by solee2            #+#    #+#             */
/*   Updated: 2023/10/25 20:21:28 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	initialize_info(int argc, char **argv, t_info *info)
{
	if ((int)ft_atoi(argv[1]) != 0)
		info->num_philo = (int)ft_atoi(argv[1]);
	else
	{
		return (print_error("ERROR) Invalid Input", NULL), ERROR);
	}
	info->time_death = (int)ft_atoi(argv[2]);
	info->time_eat = (int)ft_atoi(argv[3]);
	info->time_sleep = (int)ft_atoi(argv[4]);
	if (argc == 6)
		info->num_meals = (int)ft_atoi(argv[5]);
	else
		info->num_meals = -1;
	if (info->num_philo <= 0 || info->num_philo > 200 || info->time_death < 0 \
		|| info ->time_eat < 0 || info->time_sleep < 0)
	{
		printf("ERROR) Wrong Range for Input(s)\n");
		return (1);
	}
	info->death = 0;
	info->terminate = 0;
	info->done_philos = 0;
	pthread_mutex_init(&info->print, NULL);
	pthread_mutex_init(&info->lock, NULL);
	return (0);
}

int	malloc_info(t_info *info)
{
	info->tid = malloc(sizeof(pthread_t) * info->num_philo);
	if (!info->tid)
		return (print_error("ERROR) Error Allocating Memory", info), ERROR);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->num_philo);
	if (!info->forks)
		return (print_error("ERROR) Error Allocating Memory", info), ERROR);
	info->philosophers = malloc(sizeof(t_philo) * info->num_philo);
	if (!info->philosophers)
		return (print_error("ERROR) Error Allocating Memory", info), ERROR);
	return (0);
}

void	initialize_forks(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
	{
		pthread_mutex_init(&info->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < info->num_philo)
	{
		if (i == info->num_philo - 1)
		{
			info->philosophers[i].fork_right = &info->forks[i];
			info->philosophers[i].fork_left = &info->forks[0];
		}
		else
		{
			info->philosophers[i].fork_right = &info->forks[i + 1];
			info->philosophers[i].fork_left = &info->forks[i];
		}
		i++;
	}
}

void	initialize_philosophers(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
	{
		info->philosophers[i].info = info;
		info->philosophers[i].id = i + 1;
		info->philosophers[i].count_eat = 0;
		info->philosophers[i].eating = 0;
		info->philosophers[i].time_eat = info->time_eat;
		info->philosophers[i].time_sleep = info->time_sleep;
		info->philosophers[i].time_to_die = info->time_death;
		i++;
	}
}

int	initialize_everything(int argc, char **argv, t_info *info)
{
	if (initialize_info(argc, argv, info) == ERROR)
		return (ERROR);
	if (malloc_info(info) == ERROR)
		return (ERROR);
	initialize_forks(info);
	initialize_philosophers(info);
	return (0);
}
