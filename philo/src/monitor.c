/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 23:29:44 by aroque            #+#    #+#             */
/*   Updated: 2021/07/20 00:04:22 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *death_monitor(void *arg)
{
    t_seat *seat;

    seat = arg;
    while (true)
    {
        pthread_mutex_lock(&seat->mutex);
        if (!seat->is_eating && timestamp() > seat->limit)
        {
            display(M_DIED, seat);
            pthread_mutex_unlock(&seat->mutex);
            pthread_mutex_unlock(&seat->table->death_mutex);
            return (NULL);
        }
        pthread_mutex_unlock(&seat->mutex);
        usleep(1000);
    }
    return (NULL);
}