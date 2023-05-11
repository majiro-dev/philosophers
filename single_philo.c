/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:54:03 by manujime          #+#    #+#             */
/*   Updated: 2023/05/11 15:49:43 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_single_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->table->must_eat == 0)
		return (NULL);
	if (philo->table->time_to_die == 0)
		return (NULL);
	pthread_mutex_lock(&philo->l_meal_lock);
	philo->last_meal = ft_get_current_time(philo->table);
	pthread_mutex_unlock(&philo->l_meal_lock);
	while (philo->table->time_start > ft_get_basic_time())
	{
		usleep(10);
	}
	ft_print_status(philo, 1);
	while (ft_are_we_even_alive(philo->table))
		usleep(100);
	return (NULL);
}
