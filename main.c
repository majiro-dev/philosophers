/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:12:40 by manujime          #+#    #+#             */
/*   Updated: 2023/04/25 18:44:14 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_leaks(void)
{
	system("leaks -q philo");
}

t_philo	**ft_sit_philosophers(t_table *table)
{
	int		c;
	t_philo	**academy;

	c = 0;
	academy = malloc(sizeof(t_philo) * table->philo_count + 1);
	if (!academy)
		ft_exit_error(3);
	while (c < table->philo_count)
	{
		academy[c] = NULL;
		c++;
	}
	return (academy);
}

void	ft_set_table(int argc, char **argv, t_table *table)
{
	table->existence = 1;
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
	atexit(ft_leaks);
	t_table	table;
	t_philo	**academy;

	if (argc < 4 || argc > 6)
		ft_exit_error(0);
	ft_set_table(argc, argv, &table);
	academy = ft_sit_philosophers(&table);
	while (ft_get_current_time(table) < 10000)
	{
		usleep(100);
		printf("%lld\n", ft_get_current_time(table));
	}
	printf("the simulation has ended\n");
	return (0);
}
