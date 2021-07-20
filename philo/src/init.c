/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 15:20:09 by aroque            #+#    #+#             */
/*   Updated: 2021/07/19 23:02:12 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialize_seats(t_seat seats[], t_table *table, int i)
{
	t_seat		*seat;
	
	if (i < 0)
		return ;
	seat = &seats[i];
	seat->i = (unsigned int)i;
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

int init(t_table *table, t_seat seats[])
{
	pthread_mutex_init(&table->display, NULL);
    pthread_mutex_init(&table->death_mutex, NULL);
    pthread_mutex_lock(&table->death_mutex);
	initialize_seats(seats, table, table->n);
	iterate(pthread_mutex_init_wrapper, seats, table->n);
    return (0);
}