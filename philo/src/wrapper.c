/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:34:53 by aroque            #+#    #+#             */
/*   Updated: 2021/06/25 01:24:16 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"

int	pthread_mutex_init_wrapper(void *mutex)
{
	return (pthread_mutex_init((pthread_mutex_t *)mutex, NULL));
}

int pthread_create_wrapper(void *seat)
{
	t_seat	*s;

	s = seat;
	return (pthread_create((s)->phil, NULL, (s)->routine, s));
}

int	pthread_join_wrapper(void *seat)
{
	t_seat	*s;

	s = seat;
	return (pthread_join(*(s->phil), NULL));
}
