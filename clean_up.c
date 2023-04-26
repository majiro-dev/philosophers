/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:52:14 by manujime          #+#    #+#             */
/*   Updated: 2023/04/26 11:13:37 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_free_academy(t_philo **academy)
{
	int	c;

	c = 0;
	while (academy[c])
	{
		free(academy[c]);
		c++;
	}
	free(academy);
}
