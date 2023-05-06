/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:10:18 by manujime          #+#    #+#             */
/*   Updated: 2023/05/06 15:07:16 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_bed_time(t_philo *philo)
{
	long long int	alarm;

	ft_print_status(philo, 3);
	alarm = ft_get_current_time(philo->table) + philo->table->time_to_sleep;
	while (ft_get_current_time(philo->table) < alarm)
	{
		if (!ft_are_we_even_alive(philo->table))
			break ;
		usleep(100);
	}
}

void	ft_think(t_philo *philo)
{
	long long int	the_munchies;

	the_munchies = philo->table->time_to_die
		- (ft_get_current_time(philo->table) - philo->last_meal)
		- philo->table->time_to_eat / 2;
	if (the_munchies < 0)
		the_munchies = 0;
	if (the_munchies > 500)
		the_munchies = 200;
	ft_print_status(philo, 4);
	while (ft_get_current_time(philo->table) < the_munchies)
	{
		if (!ft_are_we_even_alive(philo->table))
			break ;
		usleep(100);
	}
}

void	ft_eat_spaguetti(t_philo *philo)
{
	long long int	stop_munch;

	if (philo->table->must_eat == 0)
		return ;
	pthread_mutex_lock(&philo->table->forks[philo->fork_1]);
	ft_print_status(philo, 1);
	pthread_mutex_lock(&philo->table->forks[philo->fork_2]);
	ft_print_status(philo, 1);
	ft_print_status(philo, 2);
	philo->last_meal = ft_get_current_time(philo->table);//needs a mutex
	philo->meal_count += 1;//needs a mutex
	stop_munch = ft_get_current_time(philo->table) + philo->table->time_to_eat;
	while (ft_get_current_time(philo->table) < stop_munch)
	{
		if (!ft_are_we_even_alive(philo->table))
			break ;
		usleep(100);
	}
	pthread_mutex_unlock(&philo->table->forks[philo->fork_1]);
	pthread_mutex_unlock(&philo->table->forks[philo->fork_2]);
}

void	*ft_philo_start(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->table->time_to_die == 0)
		return (NULL);
	while (ft_are_we_even_alive(philo->table))
	{
		ft_eat_spaguetti(philo);
		ft_bed_time(philo);
		ft_think(philo);
	}
	return (NULL);
}
