/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:58:26 by aroque            #+#    #+#             */
/*   Updated: 2021/06/25 10:09:38 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <string.h>

void *philosopher(void *arg)
{
	t_seat	*seat;

	seat = arg;
	pthread_mutex_lock(seat->left_fork);
	pthread_mutex_lock(seat->right_fork);
	usleep(250000);
	printf("philo %d is thinking.\n", seat->i);
	pthread_mutex_unlock(seat->left_fork);
	pthread_mutex_unlock(seat->right_fork);
	return (0);
}

void	prepare_seat(t_seat seats[], t_table *table, int i)
{
	t_seat		*seat;
	
	if (i < 0)
		return ;
	seat = &seats[i];
	seat->i = i;
	seat->phil = &table->phil[i];
	seat->routine = philosopher;
	seat->left_fork = &table->forks[i];
	seat->right_fork = &table->forks[(i + 1) % table->n];
	seat->t_die = table->t_die;
	seat->t_eat = table->t_eat;
	seat->t_sleep = table->t_sleep;
	seat->meals = table->meals;
	prepare_seat(seats, table, i - 1);
}

int	start_the_party(t_table *table, int n)
{
	pthread_t		phil[n];
	pthread_mutex_t	forks[n];
	t_seat			seats[n];

	table->forks = forks;
	table->phil = phil;
	prepare_seat(seats, table, n);
	iterate(pthread_mutex_init_wrapper, seats, n);
	iterate(pthread_create_wrapper, seats, n);
	iterate(pthread_join_wrapper, seats, n);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_errcode	err;
	t_table		*table;

	table = NULL;
	err = get_params(argc, argv, &table);
	if (err)
		printf("Error\n");
	else
		err = start_the_party(table, table->n);
	return (err);
}
