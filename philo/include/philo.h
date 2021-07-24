/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:56:49 by aroque            #+#    #+#             */
/*   Updated: 2021/07/24 12:12:02 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/types.h>
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

struct	s_seat;

typedef struct s_table
{
	int				n;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				meals;
	pthread_mutex_t	*forks;
	pthread_mutex_t	display;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	monitor_mutex;
	unsigned long	start_time;
	struct s_seat	*seats;
}	t_table;

typedef struct s_seat
{
	int				i;
	int				meals;
	bool			alive;
	unsigned long	limit;
	pthread_t		phil;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	mutex;
	pthread_mutex_t	meal_mutex;
	t_table			*table;
}	t_seat;

unsigned long	timestamp(void);
void			display(const char *str, t_seat *seat);
void			*philosopher(void *arg);
void			take_forks(t_seat *seat);
void			drop_forks(t_seat *seat);
void			eat(t_seat *seat);
void			_sleep(t_seat *seat);
void			think(t_seat *seat);
void			*monitor(void *arg);
int				init(t_table *table);
void			clear(t_table *table);
int				ft_atoi(const char *str);
int				get_table(int argc, char *argv[], t_table *params);
int				meal_counter(t_table *table);
int				iterate(int (*func)(t_seat *), t_seat *arr, unsigned int n);

#endif
