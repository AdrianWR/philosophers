/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:56:49 by aroque            #+#    #+#             */
/*   Updated: 2021/06/19 16:47:10 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef enum e_errcode {
	ERRSYS = 134,
	EINVARG
}	t_errcode;

typedef struct s_params
{
	unsigned int	n;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	meals;
}	t_params;

typedef struct s_seat
{
	unsigned int	i;
	pthread_t		*thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				meals;
	void			*(*routine)(void *);
	void			*arg;
}	t_seat;

//typedef struct s_thread_info
//{
//}	t_thread_info;

float		timestamp(struct timeval start);
int			ft_atoi(const char *str);
t_errcode	get_params(int argc, char *argv[], t_params **params);
int			pthread_mutex_init_wrapper(void *mutex);
int			pthread_create_wrapper(void *thread_info);
int			pthread_join_wrapper(void *thread);

#endif