/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihalee <jihalee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:59:38 by solee2            #+#    #+#             */
/*   Updated: 2023/08/23 16:34:08 by jihalee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_job **lst, int fd)
{
	t_job	*job;
	t_env	**env;
	t_env	*current;

	job = *lst;
	if (job->arg)
	{
		write(fd, "env: \'", 6);
		write(fd, job->arg[0], ft_strlen(job->arg[0]));
		write(fd, "\': No such file or directory\n", 29);
		return ;
	}
	env = get_env_address();
	current = (*env);
	while (current)
	{
		write(fd, current->str, ft_strlen(current->str));
		write(fd, "\n", 1);
		current = current->next;
	}
}
