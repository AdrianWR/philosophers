/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:56:49 by aroque            #+#    #+#             */
/*   Updated: 2021/07/22 22:10:50 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

#include <sys/types.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>


# define M_TAKEN    "has taken a fork"
# define M_EAT      "is eating"
# define M_SLEEP    "is sleeping"
# define M_THINK    "is thinking"
# define M_DIED     "died"

typedef enum e_errcode {
	ERRSYS = 134,
	EINVARG
}	t_errcode;

struct s_seat;

typedef struct	s_table
{
	int	n;
	pthread_mutex_t	*forks;
	pthread_mutex_t	display;
    pthread_mutex_t death_mutex;
    pthread_mutex_t monitor_mutex;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	meals;
	unsigned long   start_time;
    struct s_seat   *seats;
}	t_table;

typedef struct s_seat
{
	int	i;
	pthread_t		phil;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	mutex;
	pthread_mutex_t	meal_mutex;
	bool			is_eating;
	bool            alive;
	unsigned long	limit;
	int				meals;
	t_table         *table;
}	t_seat;

unsigned long	timestamp(void);
void		display(const char *str, t_seat *seat);
void		*philosopher(void *arg);
void		*monitor(void *arg);
int         init(t_table *table);
int			ft_atoi(const char *str);
int			get_table(int argc, char *argv[], t_table *params);
int			iterate(int (*func)(t_seat *), t_seat *arr, unsigned int n);
int			pthread_create_wrapper(t_seat *thread_info);
int			pthread_detach_wrapper(t_seat *thread);
int			pthread_mutex_init_wrapper(t_seat *seat);
int			pthread_mutex_destroy_wrapper(t_seat *seat);

#endif
