/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:10:18 by manujime          #+#    #+#             */
/*   Updated: 2023/05/02 00:08:22 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_eat_spaguetti(t_philo *philo)
{
	if (philo->table->must_eat == 0)
		return ;
	pthread_mutex_lock(&philo->table->forks[philo->fork_1]);
////
	pthread_mutex_lock(&philo->table->forks[philo->fork_2]);
}

void	*ft_philo_start(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (ft_are_we_even_alive(philo->table))
	{
		ft_eat_spaguetti(philo);
		//sleep
		//think
	}
	while (ft_get_current_time(philo->table) < 10000)
	{
		usleep(2000000);
		printf("%lld %d my forks are %d and %d\n",
			ft_get_current_time(philo->table), philo->id,
			philo->fork_1, philo->fork_2);
	}
	return (NULL);
}
