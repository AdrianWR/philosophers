/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 22:58:00 by aroque            #+#    #+#             */
/*   Updated: 2021/07/13 23:47:27 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display(const char *str, t_seat *seat)
{
	pthread_mutex_lock(seat->display);
	printf("%ld ", timestamp());
	printf(str, seat->i);
	pthread_mutex_unlock(seat->display);
}
