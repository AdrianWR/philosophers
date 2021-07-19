/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 22:58:00 by aroque            #+#    #+#             */
/*   Updated: 2021/07/18 21:53:08 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display(const char *str, t_seat *seat)
{
	pthread_mutex_lock(&(seat->table->display));
	printf("%-10ld %d %s\n", timestamp() - seat->table->start, seat->i, str);
	pthread_mutex_unlock(&(seat->table->display));
}
