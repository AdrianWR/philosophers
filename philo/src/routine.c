/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 23:00:23 by aroque            #+#    #+#             */
/*   Updated: 2021/07/13 23:50:00 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_seat *seat)
{
	pthread_mutex_lock(seat->left_fork);
	display("%d has taken a fork.\n", seat);
	pthread_mutex_lock(seat->right_fork);
	display("%d has taken a fork.\n", seat);
}

void	drop_forks(t_seat *seat)
{
	pthread_mutex_unlock(seat->left_fork);
	pthread_mutex_unlock(seat->right_fork);
}

void	eat(t_seat *seat)
{
    seat->is_eating = true;
    seat->limit = timestamp() + seat->t_die;
	display("%d is eating.\n", seat);
	usleep(seat->t_eat * 1000);
    seat->is_eating = false;
	seat->meals--;
}

void	_sleep(t_seat *seat)
{
	usleep(seat->t_sleep * 1000);
	display("%d is sleeping.\n", seat);
}

void	think(t_seat *seat)
{
	usleep(seat->t_sleep * 1000);
	display("%d is thinking.\n", seat);
}

void	*philosopher(void *arg)
{
	t_seat	*seat;
	bool	endless;
	pthread_t	m;

	seat = arg;
	endless = !seat->meals;
	pthread_create(&m, NULL, monitor, seat);
	pthread_detach(m);
	while (endless || seat->meals)
	{
		take_forks(seat);
		eat(seat);
		drop_forks(seat);
		_sleep(seat);
		think(seat);
	}
	return (NULL);
}
