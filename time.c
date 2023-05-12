/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:32:42 by manujime          #+#    #+#             */
/*   Updated: 2023/05/12 21:48:19 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//returns the time in milliseconds since the epoch 
//(the UNIX epoch is 00:00:00 UTC on January 1, 1970).
long long	ft_get_basic_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

//returns the time since the start of the simulation
long long	ft_get_current_time(t_table *table)
{
	return (ft_get_basic_time() - table->time_start);
}
