/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:36:22 by solee2            #+#    #+#             */
/*   Updated: 2023/10/26 00:56:55 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/types.h>

# define ERROR 1
# define FORK_RIGHT "has taken a fork"
# define FORK_LEFT "has taken a fork"
# define EAT "is eating"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define DEATH "died"

struct	s_info;

typedef struct s_philo
{
	struct s_info		*info;
	int					id;
	int					count_eat;
	int					eating;
	long int			time_to_die;
	long int			time_eat;
	long int			time_sleep;
	pthread_mutex_t		*fork_right;
	pthread_mutex_t		*fork_left;
}						t_philo;

typedef struct s_info
{
	pthread_t			*tid;
	pthread_t			terminate_status;
	int					num_philo;
	int					num_meals;
	int					death;
	int					terminate;
	int					done_philos;
	t_philo				*philosophers;
	long int			time_death;
	long int			time_eat;
	long int			time_sleep;
	long int			time_start;
	pthread_mutex_t		*forks;
	pthread_mutex_t		lock;
	pthread_mutex_t		print;
}						t_info;

/* initialize.c */
int			initialize_info(int argc, char **argv, t_info *info);
int			malloc_info(t_info *info);
void		initialize_forks(t_info *info);
void		initialize_philosophers(t_info *info);
int			initialize_everything(int argc, char **argv, t_info *info);

/* one_philo.c */
int			one_usleep(useconds_t time);
void		*one_action(void *pointer);
int			one_philosopher(t_info *info);

/* two_philos.c */
void		two_hold_fork(t_philo *philo);
void		two_eat_sleep_think(t_philo *philo);
void		*two_check_status(void	*pointer);
void		*two_action_set(void *pointer);
int			two_philosophers(t_info *info);

/* many_philos.c */
void		many_hold_fork(t_philo *philo);
void		many_eat_sleep_think(t_philo *philo);
void		*many_check_status(void	*pointer);
void		*many_action_set(void *pointer);
int			many_philosophers(t_info *info);

/* get_values.c */
long int	get_time(void);
int			get_death(t_philo *philo);
int			get_terminate(t_philo *philo);

/* print.c */
void		one_print_message(char *message, t_philo *philo);
void		print_message(char *message, t_philo *philo);

/* utils.c */
int			validate_input(char **argv);
void		update_info(t_philo *philo);
int			ft_usleep(t_philo *philo, useconds_t time);

/* libft.c */
int			is_whitespace(char c);
long		ft_atoi(const char *str);
int			ft_strcmp(char *s1, char *s2);

/* free_exit.c */
void		free_info(t_info *info);
void		destroy_free(t_info *info);
int			print_error(char *message, t_info *info);

#endif
