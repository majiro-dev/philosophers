/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   existence.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:45:56 by manujime          #+#    #+#             */
/*   Updated: 2023/04/25 16:38:52 by manujime         ###   ########.fr       */
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
