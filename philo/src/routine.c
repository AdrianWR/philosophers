/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 23:00:23 by aroque            #+#    #+#             */
/*   Updated: 2021/07/24 12:22:46 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher(void *arg)
{
	t_seat		*seat;
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
	return (NULL);
}
