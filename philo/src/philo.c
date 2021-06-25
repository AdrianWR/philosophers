/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:58:26 by aroque            #+#    #+#             */
/*   Updated: 2021/06/20 20:56:16 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void *philosopher(void *arg)
{
	t_seat	*seat;

	seat = arg;
	printf("philo %d is thinking.", seat->i);
	usleep(1000);
	return (0);
}

t_seat	*prepare_seat(unsigned int i, pthread_mutex_t *forks, t_params *p)
{
	t_seat	*seat;
	
	seat = malloc(sizeof(*seat));
	if (!seat)
		return (NULL);
	memset(seat, 0, sizeof(*seat));
	seat->i = i;
	seat->left_fork = &forks[i];
	seat->left_fork = &forks[(i + 1) % p->n];
	seat->t_die = p->t_die;
	seat->t_eat = p->t_eat;
	seat->t_sleep = p->t_sleep;
	return (seat);
}


t_seat **init_thread_info(unsigned int n, pthread_mutex_t *forks, t_params *params)
{
	unsigned int	i;
	//t_seat			*seat;
	t_seat			**arr;

	i = 0;
	arr = malloc(n * sizeof(*arr));
	if (!arr)
		return (NULL);
	while (i < n)
	{
		arr[i] = prepare_seat(i, forks, params);
		i++;
	}
	return (arr);

}

int	start_the_party(t_params *params)
{
	int				err;
	unsigned int	n;
	unsigned int	i;
	t_seat			*phil;
	pthread_mutex_t	*forks;

	i = 0;
	err = 0;
	n = params->n;
	forks = malloc(n * sizeof(*forks));
	phil = malloc(n * sizeof(*phil));
	iterate(pthread_mutex_init_wrapper, forks, n);
	//phil = initialize_thread_info(philosopher, seat);
	//iterate(pthread_create_wrapper, phil, params->n);
	//iterate(prepare_seat, phil, n);
	while (!err && i < params->n)
	{
		seat = prepare_seat(i, forks, params);
		err = pthread_create(&phil[i], NULL, philosopher, seat);
		i++;
	}
	//while (!err && i < params->n)
	//{
	//	err = pthread_join(phil[i], NULL);
	//	i++;
	//}
	return (err);
}

int	main(int argc, char *argv[])
{
	t_errcode	err;
	t_params	*params;

	params = NULL;
	err = get_params(argc, argv, &params);
	if (err)
		printf("Error\n");
    else
		err = start_the_party(params);
	return (err);
}
