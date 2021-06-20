/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:11:55 by aroque            #+#    #+#             */
/*   Updated: 2021/05/24 22:39:53 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdlib.h>

float	timestamp(struct timeval start)
{
	float			stamp_s;
	float			stamp_us;
	struct timeval	now;

	gettimeofday(&now, NULL);
	stamp_s = (now.tv_sec - start.tv_sec) * 1000;
	stamp_us = (now.tv_usec - start.tv_usec) / 1000;
	return (stamp_s + stamp_us);
}
