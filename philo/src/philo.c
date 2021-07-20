/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:58:26 by aroque            #+#    #+#             */
/*   Updated: 2021/07/20 00:00:59 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void    clear(t_table *table, t_seat seats[])
{
    pthread_mutex_destroy(&table->death_mutex);
    pthread_mutex_destroy(&table->display);
	iterate(pthread_mutex_destroy_wrapper, seats, table->n);
}

int	start(t_table table, int n)
{
    pthread_t       eta;
	pthread_mutex_t	forks[n];
	t_seat			seats[n];

	table.forks = forks;
    table.seats = seats;
    init(&table, seats);
    if (!table.meals)
    {
        pthread_create(&eta, NULL, meal_monitor, seats);
        pthread_detach(eta);
        usleep(100);
    }
	iterate(pthread_create_wrapper, seats, n);
	iterate(pthread_detach_wrapper, seats, n);
    pthread_mutex_lock(&table.death_mutex);
    pthread_mutex_unlock(&table.death_mutex);
    clear(&table, seats);
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