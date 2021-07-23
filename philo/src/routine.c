/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 23:00:23 by aroque            #+#    #+#             */
/*   Updated: 2021/07/22 23:57:36 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_seat *seat)
{
    //if (seat->i % 2)
    if (seat->i < (seat->i + 1) % seat->table->n)
    {
        pthread_mutex_lock(seat->right_fork);
        display(M_TAKEN, seat);
        pthread_mutex_lock(seat->left_fork);
        display(M_TAKEN, seat);
    }
    else
    {
        pthread_mutex_lock(seat->left_fork);
        display(M_TAKEN, seat);
        pthread_mutex_lock(seat->right_fork);
        display(M_TAKEN, seat);
    }
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
	usleep(seat->table->t_sleep * 1000);
	display(M_SLEEP, seat);
}

void	think(t_seat *seat)
{
    if (seat->alive)
	    display(M_THINK, seat);
}

void	*philosopher(void *arg)
{
	t_seat      *seat;
	pthread_t	m;

	seat = arg;
	pthread_create(&m, NULL, &monitor, seat);
    pthread_detach(m);
	while (seat->alive)
	{
		take_forks(seat);
		eat(seat);
		drop_forks(seat);
		_sleep(seat);
		think(seat);
	}
    pthread_mutex_unlock(&seat->meal_mutex);
	return (NULL);
}