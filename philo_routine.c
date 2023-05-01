/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:10:18 by manujime          #+#    #+#             */
/*   Updated: 2023/05/01 15:31:06 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_philo_start(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (ft_get_current_time(philo->table) < 10000)
	{
		usleep(2000000);
		printf("%lld %d is saying hi\n",
			ft_get_current_time(philo->table), philo->id);
	}
	return (NULL);
}
