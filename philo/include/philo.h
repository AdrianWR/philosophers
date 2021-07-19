/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:56:49 by aroque            #+#    #+#             */
/*   Updated: 2021/07/18 21:56:54 by aroque           ###   ########.fr       */
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

typedef enum e_errcode {
	ERRSYS = 134,
	EINVARG
}	t_errcode;

typedef struct	s_table
{
	unsigned int	n;
	pthread_t		*phil;
	pthread_mutex_t	*forks;
	pthread_mutex_t	display;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	meals;
	unsigned long   start;
}	t_table;

typedef struct s_seat
{
	unsigned int	i;
	pthread_t		*phil;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	mutex;
	bool			is_eating;
	bool            alive;
	unsigned long	limit;
	int				meals;
	t_table         *table;
	void			*(*routine)(void *);
}	t_seat;


unsigned long	timestamp(void);
void		display(const char *str, t_seat *seat);
void		*philosopher(void *arg);
void		*monitor(void *arg);
int			ft_atoi(const char *str);
int			get_table(int argc, char *argv[], t_table *params);
int			iterate(int (*func)(t_seat *), t_seat *arr, unsigned int n);
int			pthread_create_wrapper(t_seat *thread_info);
int			pthread_detach_wrapper(t_seat *thread);
int			pthread_mutex_init_wrapper(t_seat *seat);
int			pthread_mutex_destroy_wrapper(t_seat *seat);

#endif
