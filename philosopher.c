/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solee2 <solee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:36:12 by solee2            #+#    #+#             */
/*   Updated: 2023/10/26 00:57:15 by solee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc < 5 || argc > 6)
		return (print_error("ERROR) Wrong Number of Arguments", NULL), ERROR);
	if (validate_input(argv) == ERROR)
		return (ERROR);
	if (initialize_everything(argc, argv, &info) == ERROR)
		return (ERROR);
	if (info.num_philo == 1)
		return (one_philosopher(&info));
	else
	{
		if (many_philosophers(&info) == ERROR)
			return (ERROR);
	}
	destroy_free(&info);
	return (0);
}
