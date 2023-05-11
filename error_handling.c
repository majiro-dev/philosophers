/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:58:04 by manujime          #+#    #+#             */
/*   Updated: 2023/05/11 17:17:22 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_exit_error(int n, int *test)
{
	if (*test == 0)
		return ;
	if (n == 0)
		printf("Error, non valid argument\n");
	if (n == 1)
		printf("Error, PLACEHOLDER\n");
	if (n == 2)
		printf("Error, too big of an argument\n");
	if (n == 3)
		printf("Error, bad academy formation\n");
	if (n == 4)
		printf("Error, bad fork placement\n");
	if (n == 5)
		printf("Error, bad philo thread\n");
	*test = 0;
}

int	ft_atoi(char *param, t_table *table)
{
	int				c;
	long long int	nbr;

	c = 0;
	nbr = 0;
	while (param[c] && param[c] >= '0' && param[c] <= '9')
		c++;
	if (param[c] != '\0')
		ft_exit_error(0, &table->existence);
	c = 0;
	while (param[c] && param[c] >= '0' && param[c] <= '9')
	{
		nbr = (nbr * 10) + (param[c] - '0');
		c++;
	}
	if (nbr > INT_MAX || nbr < INT_MIN)
		ft_exit_error(2, &table->existence);
	return (nbr);
}
