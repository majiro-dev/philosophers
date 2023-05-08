/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 23:07:52 by manujime          #+#    #+#             */
/*   Updated: 2023/05/08 15:32:49 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print_status(t_philo *philo, int s)
{
	pthread_mutex_lock(&philo->table->talking_stick);
	if (s == 5)
		printf("%s%lld %d %s%s\n", RED, ft_get_current_time(philo->table),
			philo->id, "has died", END);
	if (!ft_are_we_even_alive(philo->table))
	{
		pthread_mutex_unlock(&philo->table->talking_stick);
		return ;
	}
	if (s == 1)
		printf("%lld %d %s\n", ft_get_current_time(philo->table), philo->id,
			"has taken a fork");
	if (s == 2)
		printf("%lld %d %s\n", ft_get_current_time(philo->table), philo->id,
			"is eating");
	if (s == 3)
		printf("%lld %d %s\n", ft_get_current_time(philo->table), philo->id,
			"is sleeping");
	if (s == 4)
		printf("%lld %d %s\n", ft_get_current_time(philo->table), philo->id,
			"is thinking");
	pthread_mutex_unlock(&philo->table->talking_stick);
}