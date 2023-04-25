/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:19:42 by manujime          #+#    #+#             */
/*   Updated: 2023/04/25 18:21:08 by manujime         ###   ########.fr       */
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
# include <limits.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"

typedef struct s_fork
{
	pthread_mutex_t	lock;
	int				available;
}	t_fork;

typedef struct s_table
{
	pthread_t		sim;
	pthread_mutex_t	cynical_lock;
	int				existence;
	long long		time_start;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				must_eat;
	int				philo_count;
	t_fork			*forks;
}	t_table;

typedef struct s_philo
{
	int			id;
	pthread_t	p_thread;
	long long	last_meal;
	int			meal_count;
	t_table		table;

}	t_philo;

//utils
long long	ft_get_basic_time(void);
long long	ft_get_current_time(t_table table);
//error_handling
void		ft_exit_error(int n);
int			ft_atoi(char *param);

#endif
