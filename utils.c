/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:36:31 by solee2            #+#    #+#             */
/*   Updated: 2023/10/25 20:24:08 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	validate_input(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (print_error("ERROR) Invalid Input", NULL), ERROR);
			j++;
		}
		i++;
	}
	return (0);
}

void	update_info(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->lock);
		philo->info->done_philos++;
	if (philo->info->done_philos == philo->info->num_philo)
		philo->info->terminate = 1;
	pthread_mutex_unlock(&philo->info->lock);
}

int	ft_usleep(t_philo *philo, useconds_t time)
{
	long int	start;
	long int	c_time;

	start = get_time();
	c_time = start;
	while ((c_time - start) < time)
	{
		if (c_time >= philo->time_to_die)
			print_message(DEATH, philo);
		c_time = get_time();
		usleep(50);
	}
	return (0);
}
