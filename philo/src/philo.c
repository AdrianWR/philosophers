/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:58:26 by aroque            #+#    #+#             */
/*   Updated: 2021/07/19 08:52:13 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	initialize_seats(t_seat seats[], t_table *table, int i)
{
	t_seat		*seat;
	
	if (i < 0)
		return ;
	seat = &seats[i];
	seat->i = (unsigned int)i;
	seat->phil = &table->phil[i];
	seat->routine = philosopher;
	seat->left_fork = &table->forks[i];
	seat->right_fork = &table->forks[(i + 1) % table->n];
    seat->is_eating = false;
    seat->limit = timestamp() + table->t_die;
	seat->meals = table->meals;
    seat->alive = true;
    seat->table = table;
	initialize_seats(seats, table, i - 1);
}

int	start(t_table table, int n)
{
	pthread_t		phil[n];
	pthread_mutex_t	forks[n];
	t_seat			seats[n];

	table.forks = forks;
	table.phil = phil;
	pthread_mutex_init(&table.display, NULL);
    pthread_mutex_init(&table.death_mutex, NULL);
    pthread_mutex_lock(&table.death_mutex);
	initialize_seats(seats, &table, n);
	iterate(pthread_mutex_init_wrapper, seats, n);
	iterate(pthread_create_wrapper, seats, n);
	iterate(pthread_detach_wrapper, seats, n);
	iterate(pthread_mutex_destroy_wrapper, seats, n);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_errcode	err;
	t_table		*table;

	table = malloc(sizeof(*table));
	err = get_table(argc, argv, table);
	if (err)
		printf("Error\n");
	else
		err = start(*table, table->n);
	free(table);
	return (err);
}