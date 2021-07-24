/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:21:25 by aroque            #+#    #+#             */
/*   Updated: 2021/07/24 15:00:12 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_seat *seat)
{
	pthread_mutex_lock(seat->left_fork);
	display(M_TAKEN, seat);
	pthread_mutex_lock(seat->right_fork);
	display(M_TAKEN, seat);
}

void	drop_forks(t_seat *seat)
{
	pthread_mutex_unlock(seat->right_fork);
	pthread_mutex_unlock(seat->left_fork);
}

void	eat(t_seat *seat)
{
	pthread_mutex_lock(&seat->mutex);
	seat->limit = timestamp() + seat->table->t_die;
	display(M_EAT, seat);
	usleep(seat->table->t_eat * 1000);
	seat->meals--;
	pthread_mutex_unlock(&seat->mutex);
}

void	_sleep(t_seat *seat)
{
	display(M_SLEEP, seat);
	usleep(seat->table->t_sleep * 1000);
}

void	think(t_seat *seat)
{
	if (seat->alive)
		display(M_THINK, seat);
}
