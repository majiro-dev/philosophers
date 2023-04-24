/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:19:42 by manujime          #+#    #+#             */
/*   Updated: 2023/04/24 19:38:26 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int			id;
	long long	last_meal;
	int			meal_count;
	t_table		table;

}	t_philo;

typedef struct s_table
{
	long long	time_start;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	int			must_eat;
	int			philo_count;
}	t_table;

typedef struct s_fork
{
	int		available;
}	t_fork;

//utils
long long	ft_get_time(void);

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"

#endif
