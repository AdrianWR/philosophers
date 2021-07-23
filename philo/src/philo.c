/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:58:26 by aroque            #+#    #+#             */
/*   Updated: 2021/07/22 23:55:00 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    clear(t_table *table)
{
	pthread_mutex_destroy(&table->monitor_mutex);
	pthread_mutex_destroy(&table->death_mutex);
	pthread_mutex_destroy(&table->display);
	iterate(pthread_mutex_destroy_wrapper, table->seats, table->n);
}

int meal_mutex_wrapper(t_seat *seat)
{
	pthread_mutex_lock(&seat->meal_mutex);
	return (0);
}

void *meal_over(void *arg)
{
    t_table *t;

    t = arg;
	iterate(meal_mutex_wrapper, t->seats, t->n);
	pthread_mutex_unlock(&t->death_mutex);
	return (NULL);
}

int	start(t_table table, int n)
{
    pthread_t       meal_counter;
	pthread_mutex_t	forks[n];
	t_seat			seats[n];

	table.forks = forks;
	table.seats = seats;
	init(&table);
	iterate(pthread_create_wrapper, seats, n);
    pthread_create(&meal_counter, NULL, &meal_over, &table);
    pthread_detach(meal_counter);
	pthread_mutex_lock(&table.death_mutex);
	pthread_mutex_unlock(&table.death_mutex);
	clear(&table);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_errcode	err;
	t_table		table;

	err = get_table(argc, argv, &table);
	if (err)
		printf("Error\n");
	else
		err = start(table, table.n);
	return (err);
}