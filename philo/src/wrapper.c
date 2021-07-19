/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:34:53 by aroque            #+#    #+#             */
/*   Updated: 2021/07/18 14:49:43 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"

int	pthread_mutex_init_wrapper(t_seat *seat)
{
	return (pthread_mutex_init(seat->left_fork, NULL));
}

int	pthread_mutex_destroy_wrapper(t_seat *seat)
{
	return (pthread_mutex_destroy(seat->left_fork));
}

int pthread_create_wrapper(t_seat *seat)
{
	return (pthread_create(seat->phil, NULL, seat->routine, seat));
}

int	pthread_detach_wrapper(t_seat *seat)
{
	return (pthread_join(*(seat->phil), NULL));
}