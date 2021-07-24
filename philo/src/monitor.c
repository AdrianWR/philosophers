/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 23:29:44 by aroque            #+#    #+#             */
/*   Updated: 2021/07/24 14:57:43 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	death_monitor(void *arg)
{
	t_seat	*seat;

	seat = arg;
	if (timestamp() > seat->limit)
	{
		pthread_mutex_lock(&seat->table->monitor_mutex);
		display(M_DIED, seat);
		pthread_mutex_unlock(&seat->mutex);
		pthread_mutex_unlock(&seat->table->death_mutex);
		return (true);
	}
	return (false);
}

static bool	meal_monitor(void *arg)
{
	t_seat	*seat;

	seat = arg;
	if (seat->table->meals && !seat->meals)
	{
		seat->alive = false;
		pthread_mutex_unlock(&seat->meal_mutex);
		pthread_mutex_unlock(&seat->mutex);
		return (true);
	}
	return (false);
}

void	*monitor(void *arg)
{
	t_seat	*seat;

	seat = arg;
	while (true)
	{
		pthread_mutex_lock(&seat->mutex);
		if (death_monitor(seat))
			return (NULL);
		if (meal_monitor(seat))
			return (NULL);
		pthread_mutex_unlock(&seat->mutex);
	}
	return (NULL);
}
