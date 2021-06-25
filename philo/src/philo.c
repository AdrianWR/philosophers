/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:58:26 by aroque            #+#    #+#             */
/*   Updated: 2021/06/25 09:31:52 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <string.h>

void *philosopher(void *arg)
{
	t_seat	*seat;

	seat = arg;
	printf("philo %d is thinking.\n", seat->i);
	usleep(1000);
	return (0);
}

t_seat	prepare_seat(unsigned int i, t_table *table)
{
	t_seat		seat;
	
	seat.i = i;
	seat.phil = &table->phil[i];
	seat.left_fork = &table->forks[i];
	seat.right_fork = &table->forks[(i + 1) % table->n];
	seat.t_die = table->t_die;
	seat.t_eat = table->t_eat;
	seat.t_sleep = table->t_sleep;
	seat.meals = table->meals;
	seat.routine = philosopher;
	return (seat);
}


int	start_seats(t_table *table, t_seat seats[])
{
	unsigned int	i;

	i = -1;
	while (++i < table->n)
		seats[i] = prepare_seat(i, table);
	return (0);
}

int	start_the_party(t_table *table)
{
	pthread_t		phil[table->n];
	pthread_mutex_t	forks[table->n];
	t_seat			seats[table->n];

	table->forks = forks;
	table->phil = phil;
	start_seats(table, seats);
	iterate(pthread_mutex_init_wrapper, seats, table->n);
	iterate(pthread_create_wrapper, seats, table->n);
	iterate(pthread_join_wrapper, seats, table->n);
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
		err = start_the_party(table);
	return (err);
}
