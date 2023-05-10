/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:52:14 by manujime          #+#    #+#             */
/*   Updated: 2023/05/10 19:34:49 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

void	ft_clean_table(t_table *table)
{
	int	c;

	c = 0;
	pthread_mutex_destroy(&table->cynical_lock);
	while (c < table->philo_count)
	{
		pthread_mutex_destroy(&table->forks[c]);
		c++;
	}
	pthread_mutex_destroy(&table->talking_stick);
	pthread_mutex_destroy(&table->cynical_lock);
	free(table->forks);
}

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

void	ft_clean_up(t_philo **academy, t_table *table)
{
	pthread_mutex_lock(&academy[0]->m_count_lock);
	printf("the simulation has ended\n");
	pthread_mutex_unlock(&academy[0]->m_count_lock);
	usleep(100000);
	ft_join_philos(academy, table);
	ft_free_academy(academy);
	ft_clean_table(table);
}
