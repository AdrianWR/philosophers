/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 23:44:37 by aroque            #+#    #+#             */
/*   Updated: 2021/07/23 23:56:06 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	pthread_mutex_destroy_wrapper(t_seat *seat)
{
	pthread_mutex_destroy(&seat->mutex);
	pthread_mutex_destroy(seat->left_fork);
	return (0);
}

void	clear(t_table *table)
{
	pthread_mutex_destroy(&table->monitor_mutex);
	pthread_mutex_destroy(&table->death_mutex);
	pthread_mutex_destroy(&table->display);
	iterate(pthread_mutex_destroy_wrapper, table->seats, table->n);
	free(table->seats);
	free(table->forks);
}
