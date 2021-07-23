/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:58:26 by aroque            #+#    #+#             */
/*   Updated: 2021/07/24 00:09:57 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pthread_create_wrapper(t_seat *seat)
{
	pthread_create(&seat->phil, NULL, philosopher, seat);
	pthread_detach(seat->phil);
	usleep(50);
	return (0);
}

int	start(t_table table, int n)
{
	init(&table);
	iterate(pthread_create_wrapper, table.seats, n);
	meal_counter(&table);
	pthread_mutex_lock(&table.death_mutex);
	pthread_mutex_unlock(&table.death_mutex);
	clear(&table);
	return (0);
}

int	main(int argc, char *argv[])
{
	int			err;
	t_table		table;

	err = get_table(argc, argv, &table);
	if (err)
		printf("Error\n");
	else
		err = start(table, table.n);
	return (err);
}
