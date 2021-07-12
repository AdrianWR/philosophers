/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 22:58:00 by aroque            #+#    #+#             */
/*   Updated: 2021/07/06 22:58:14 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display(const char *str, t_seat *seat)
{
	pthread_mutex_lock(seat->display);
	printf("%lu ", timestamp());
	printf(str, seat->i);
	pthread_mutex_unlock(seat->display);
}
