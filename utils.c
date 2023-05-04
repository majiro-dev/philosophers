/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 23:07:52 by manujime          #+#    #+#             */
/*   Updated: 2023/05/05 00:40:09 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print_status(t_philo *philo, int s)
{
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
}
