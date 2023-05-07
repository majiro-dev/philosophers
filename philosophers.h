/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:19:42 by manujime          #+#    #+#             */
/*   Updated: 2023/05/07 00:55:19 by manujime         ###   ########.fr       */
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
# define BLUE "\033[0;36m"
# define END "\033[0m"

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
	pthread_mutex_t	*forks;
}	t_table;

typedef struct s_philo
{
	int				id;
	pthread_t		p_thread;
	pthread_mutex_t	l_meal_lock;
	long long		last_meal;
	pthread_mutex_t	m_count_lock;
	int				meal_count;
	int				fork_1;
	int				fork_2;
	t_table			*table;

}	t_philo;

//time
long long	ft_get_basic_time(void);
long long	ft_get_current_time(t_table *table);
//error_handling
void		ft_exit_error(int n);
int			ft_atoi(char *param);
//clean_up
void		ft_free_academy(t_philo **academy);
//existence
int			ft_are_we_even_alive(t_table *table);
void		ft_beginning_of_existence(t_philo **philo, t_table *table);
int			ft_ur_no_more(t_philo *philo);
int			ft_philo_check(t_philo **academy);
//philo_routine
void		*ft_philo_start(void *arg);
//utils
void		ft_print_status(t_philo *philo, int s);
#endif
