/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 00:02:27 by aroque            #+#    #+#             */
/*   Updated: 2021/06/25 09:29:58 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** int iterate(int (*func)(void *), void *arg, int n): 
**
** Apply function func(void *) to each element of array *arr.
** The size of the array must be given by n. The return of the
** function is the the return of func, given that an error might
** occur. In case of sucess, iterate returns zero.
*/

int	iterate_void(int (*func)(void *), void *arr, int n)
{
	int	i;
	int err;

	i = -1;
	err = 0;
	while (++i < n && !err)
		err = func(&arr[i]);
	return (err);
}

int	iterate(int (*func)(t_seat *), t_seat *arr, int n)
{
	int	i;
	int err;

	i = -1;
	err = 0;
	while (++i < n && !err)
		err = func(&arr[i]);
	return (err);
}
