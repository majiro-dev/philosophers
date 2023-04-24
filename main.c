/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:12:40 by manujime          #+#    #+#             */
/*   Updated: 2023/04/25 00:31:54 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_set_table(int argc, char **argv, t_table	*table)
{
	table->time_start = ft_get_basic_time();
	table->philo_count = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->must_eat = ft_atoi(argv[5]);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < 4 || argc > 6)
		ft_exit_error(0);
	ft_set_table(argc, argv, &table);
	while (ft_get_current_time(table) < 10000)
	{
		usleep(1000);
		printf("%lld", ft_get_current_time(table));
	}
	return (0);
}
