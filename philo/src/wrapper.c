/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:34:53 by aroque            #+#    #+#             */
/*   Updated: 2021/06/19 15:30:08 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"

int	pthread_mutex_init_wrapper(void *mutex)
{
	return (pthread_mutex_init((pthread_mutex_t *) mutex, NULL));
}

int pthread_create_wrapper(void *thread_info)
{
	t_seat	*s;

	s = thread_info;
	return (pthread_create(s->thread, NULL, s->start_routine, s->arg));
}

int	pthread_join_wrapper(void *thread)
{
	return (pthread_join(*(pthread_t *)(thread), NULL));
}
