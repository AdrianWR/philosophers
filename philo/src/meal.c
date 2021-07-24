/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 22:46:49 by aroque            #+#    #+#             */
/*   Updated: 2021/07/24 00:46:46 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	meal_mutex_wrapper(t_seat *seat)
{
	return (pthread_mutex_lock(&seat->meal_mutex));
}

static void	*meal_over(void *arg)
{
	t_table	*t;

	t = arg;
	iterate(meal_mutex_wrapper, t->seats, t->n);
	pthread_mutex_unlock(&t->death_mutex);
	return (NULL);
}

int	meal_counter(t_table *table)
{
	pthread_t		meal_counter;

	pthread_create(&meal_counter, NULL, &meal_over, table);
	pthread_detach(meal_counter);
	return (0);
}
