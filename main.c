/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:12:40 by manujime          #+#    #+#             */
/*   Updated: 2023/05/12 15:52:03 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_leaks(void)
{
	system("leaks -q philo");
}

void	ft_designate_forks(t_philo *philo)
{
	philo->fork_1 = philo->id;
	philo->fork_2 = (philo->id + 1) % philo->table->philo_count;
	if (philo->id % 2 == 0)
	{
		philo->fork_1 = (philo->id + 1) % philo->table->philo_count;
		philo->fork_2 = philo->id;
	}
}

void	ft_set_forks(t_table *table)
{
	int				c;

	c = 1;
	while (c < table->philo_count)
	{
		if (pthread_mutex_init(&table->forks[c], NULL) != 0)
			ft_exit_error(4, &table->existence);
		c++;
	}
}

t_philo	**ft_sit_philosophers(t_table *table)
{
	int		c;
	t_philo	**academy;

	c = 0;
	academy = malloc(sizeof(t_philo *) * (table->philo_count + 1));
	if (!academy)
		ft_exit_error(3, &table->existence);
	while (c < table->philo_count)
	{
		academy[c] = malloc(sizeof(t_philo));
		if (!academy[c])
			ft_exit_error(3, &table->existence);
		academy[c]->id = c + 1;
		academy[c]->meal_count = 0;
		academy[c]->last_meal = 0;
		academy[c]->table = table;
		if (pthread_mutex_init(&academy[c]->m_count_lock, NULL))
			ft_exit_error(3, &table->existence);
		if (pthread_mutex_init(&academy[c]->l_meal_lock, NULL))
			ft_exit_error(3, &table->existence);
		ft_designate_forks(academy[c]);
		c++;
	}
	academy[c] = NULL;
	return (academy);
}

void	ft_set_table(int argc, char **argv, t_table *table)
{
	table->philo_count = ft_atoi(argv[1], table);
	if (table->philo_count == 0 || table->philo_count > 200)
		ft_exit_error(0, &table->existence);
	table->time_to_die = ft_atoi(argv[2], table);
	table->time_to_eat = ft_atoi(argv[3], table);
	table->time_to_sleep = ft_atoi(argv[4], table);
	if (argc == 6)
		table->must_eat = ft_atoi(argv[5], table);
	else
		table->must_eat = -1;
	if (pthread_mutex_init(&table->talking_stick, NULL))
		ft_exit_error(3, &table->existence);
	table->forks = malloc(sizeof(pthread_mutex_t) * (table->philo_count));
	if (!table->forks)
		ft_exit_error(4, &table->existence);
	ft_set_forks(table);
}

int	main(int argc, char **argv)
{
	atexit(ft_leaks);
	t_table	table;
	t_philo	**academy;

	table.existence = 1;
	if (argc == 5 || argc == 6)
	{
		ft_set_table(argc, argv, &table);
		academy = ft_sit_philosophers(&table);
		if (ft_are_we_even_alive(&table))
		{
			ft_beginning_of_existence(academy, &table);
			ft_keep_this_going(academy);
		}
		usleep(1000);
		ft_clean_up(academy, &table);
	}
	else
		ft_exit_error(0, &table.existence);
	return (0);
}
