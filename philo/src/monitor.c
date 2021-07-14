/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 23:29:44 by aroque            #+#    #+#             */
/*   Updated: 2021/07/13 23:52:02 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *monitor(void *arg)
{
    t_seat *seat;
    bool    died;

    seat = arg;
    died = false;
    while (true)
    {
        if (!died && !seat->is_eating && timestamp() > seat->limit)
        {
            died = true;
            display("%d has died.\n", seat);
        }
        usleep(1000);
    }
    return (NULL);
}