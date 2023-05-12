/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:52:14 by manujime          #+#    #+#             */
/*   Updated: 2023/05/12 21:47:48 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//frees the academy and destroys las meal mutex and meal count mutex for each
//philosopher
void	ft_free_academy(t_philo **academy)
{
	int	c;

	c = 0;
	while (academy[c])
	{
		pthread_mutex_destroy(&academy[c]->l_meal_lock);
		pthread_mutex_destroy(&academy[c]->m_count_lock);
		free(academy[c]);
		c++;
	}
	free(academy);
}

//destroys forks' mutexes, existece mutex and talking mutex
void	ft_clean_table(t_table *table)
{
	int	c;

	c = 0;
	while (c < table->philo_count - 1)
	{
		pthread_mutex_destroy(&table->forks[c]);
		c++;
	}
	pthread_mutex_destroy(&table->cynical_lock);
	pthread_mutex_destroy(&table->talking_stick);
	free(table->forks);
}

//joins all philo threads with main thread
void	ft_join_philos(t_philo **philo, t_table *table)
{
	int	c;

	c = 0;
	while (c < table->philo_count)
	{
		pthread_join(philo[c]->p_thread, NULL);
		c++;
	}
}

//joins threads, frees memory and destroys mutexes
void	ft_clean_up(t_philo **academy, t_table *table)
{
	usleep(100000);
	ft_join_philos(academy, table);
	ft_free_academy(academy);
	ft_clean_table(table);
}
