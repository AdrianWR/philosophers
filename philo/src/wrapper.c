/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:34:53 by aroque            #+#    #+#             */
/*   Updated: 2021/07/22 23:26:46 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"

int	pthread_mutex_destroy_wrapper(t_seat *seat)
{
    pthread_mutex_destroy(&seat->mutex);
	pthread_mutex_destroy(seat->left_fork);
    return (0);
}

int pthread_create_wrapper(t_seat *seat)
{
	pthread_create(&seat->phil, NULL, philosopher, seat);
	pthread_detach(seat->phil);
    //usleep(1000);
    return (0);
}