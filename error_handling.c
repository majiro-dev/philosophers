/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:58:04 by manujime          #+#    #+#             */
/*   Updated: 2023/04/26 15:28:47 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_exit_error(int n)
{
	if (n == 0)
		printf("Error, wrong number of arguments\n");
	if (n == 1)
		printf("Error, non numeric arguments\n");
	if (n == 2)
		printf("Error, too big of an argument\n");
	if (n == 3)
		printf("Error, bad academy formation\n");
	if (n == 4)
		printf("Error, bad fork placement\n");
	exit(1);
}

int	ft_atoi(char *param)
{
	int				c;
	long long int	nbr;

	c = 0;
	nbr = 0;
	while (param[c] && param[c] >= '0' && param[c] <= '9')
		c++;
	if (param[c] != '\0')
		ft_exit_error(1);
	c = 0;
	while (param[c] && param[c] >= '0' && param[c] <= '9')
	{
		nbr = (nbr * 10) + (param[c] - '0');
		c++;
	}
	if (nbr > INT_MAX)
		ft_exit_error(2);
	return (nbr);
}
