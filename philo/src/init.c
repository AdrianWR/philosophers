/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 15:20:09 by aroque            #+#    #+#             */
/*   Updated: 2021/07/23 22:22:43 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialize_seats(t_seat seats[], t_table *table, int i)
{
	t_seat		*seat;

	if (i < 0)
		return ;
	seat = &seats[i];
	seat->i = i;
	seat->left_fork = &table->forks[i];
	seat->right_fork = &table->forks[(i + 1) % table->n];
	seat->limit = timestamp() + table->t_die;
	seat->meals = table->meals;
	seat->alive = true;
	seat->table = table;
	pthread_mutex_init(seat->left_fork, NULL);
	pthread_mutex_init(&seat->mutex, NULL);
	pthread_mutex_init(&seat->meal_mutex, NULL);
	pthread_mutex_lock(&seat->meal_mutex);
	initialize_seats(seats, table, i - 1);
}

int	init(t_table *table)
{
	table->someone_died = false;
	pthread_mutex_init(&table->display, NULL);
	pthread_mutex_init(&table->death_mutex, NULL);
	pthread_mutex_init(&table->monitor_mutex, NULL);
	pthread_mutex_lock(&table->death_mutex);
	initialize_seats(table->seats, table, table->n - 1);
	return (0);
}
