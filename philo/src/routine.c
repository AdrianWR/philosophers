/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 23:00:23 by aroque            #+#    #+#             */
/*   Updated: 2021/07/19 08:46:42 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_seat *seat)
{
    if (seat->i % 2)
    {
    	pthread_mutex_lock(seat->left_fork);
    	display("has taken a fork.", seat);
    	pthread_mutex_lock(seat->right_fork);
    	display("has taken a fork.", seat);
    }
    else
    {
    	pthread_mutex_lock(seat->right_fork);
    	display("has taken a fork.", seat);
    	pthread_mutex_lock(seat->left_fork);
    	display("has taken a fork.", seat);
    }
}

void	drop_forks(t_seat *seat)
{
	pthread_mutex_unlock(seat->right_fork);
	pthread_mutex_unlock(seat->left_fork);
}

void	eat(t_seat *seat)
{
    pthread_mutex_lock(&(seat->mutex));
    seat->is_eating = true;
    seat->limit = timestamp() + seat->table->t_die;
	display("is eating.", seat);
	usleep(seat->table->t_eat * 1000);
    seat->is_eating = false;
	seat->meals--;
    pthread_mutex_unlock(&(seat->mutex));
}

void	_sleep(t_seat *seat)
{
	usleep(seat->table->t_sleep * 1000);
	display("is sleeping.", seat);
}

void	think(t_seat *seat)
{
	usleep(seat->table->t_sleep * 1000);
	display("is thinking.", seat);
}

void	*philosopher(void *arg)
{
	t_seat	*seat;
	bool	endless;
	//pthread_t	m;

	seat = arg;
	endless = !seat->meals;
	//pthread_create(&m, NULL, monitor, seat);
	//pthread_detach(m);
	while (seat->alive && (endless || seat->meals))
	{
		take_forks(seat);
		eat(seat);
		drop_forks(seat);
		_sleep(seat);
		think(seat);
	}
	return (NULL);
}
