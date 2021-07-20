/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:34:53 by aroque            #+#    #+#             */
/*   Updated: 2021/07/19 23:06:15 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"

int	pthread_mutex_init_wrapper(t_seat *seat)
{
    pthread_mutex_init(&seat->mutex, NULL);
    pthread_mutex_init(&seat->meal_mutex, NULL);
    pthread_mutex_lock(&seat->meal_mutex);
	pthread_mutex_init(seat->left_fork, NULL);
    return (0);
}

int	pthread_mutex_destroy_wrapper(t_seat *seat)
{
    pthread_mutex_destroy(&seat->mutex);
	pthread_mutex_destroy(seat->left_fork);
    return (0);
}

int pthread_create_wrapper(t_seat *seat)
{
	return (pthread_create(&seat->phil, NULL, philosopher, seat));
}

int	pthread_detach_wrapper(t_seat *seat)
{
	return (pthread_detach(seat->phil));
}