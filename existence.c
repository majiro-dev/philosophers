/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   existence.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:45:56 by manujime          #+#    #+#             */
/*   Updated: 2023/05/07 16:23:24 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_are_we_even_alive(t_table *table)
{
	pthread_mutex_lock(&table->cynical_lock);
	if (table->existence == 1)
	{
		pthread_mutex_unlock(&table->cynical_lock);
		return (1);
	}
	else
		return (0);
	pthread_mutex_unlock(&table->cynical_lock);
}

void	ft_beginning_of_existence(t_philo **philo, t_table *table)
{
	int	c;

	c = 0;
	while (c < table->philo_count)
	{
		if (pthread_create(&philo[c]->p_thread, NULL, &ft_philo_start,
				philo[c]) != 0)
			ft_exit_error(5);
		c++;
	}
}

int	ft_ur_no_more(t_philo *philo)
{
	if ((ft_get_current_time(philo->table) - philo->last_meal)
		>= philo->table->time_to_die)
	{
		pthread_mutex_lock(&philo->table->cynical_lock);
		philo->table->existence = 0;
		ft_print_status(philo, 5);
		pthread_mutex_unlock(&philo->table->cynical_lock);
		return (1);
	}
	return (0);
}

int	ft_philo_check(t_philo **academy)
{
	int	c;
	int	satiated;

	satiated = 1;
	c = 0;
	while (academy[c])
	{
		if (ft_ur_no_more(academy[c]))
			return (1);
		pthread_mutex_lock(&academy[c]->l_meal_lock);
		if (academy[c]->table->must_eat == -1
			|| academy[c]->meal_count < academy[c]->table->must_eat)
			satiated = 0;
		pthread_mutex_unlock(&academy[c]->l_meal_lock);
		c++;
	}
	return (satiated);
}
