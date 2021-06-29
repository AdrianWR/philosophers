/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 00:02:27 by aroque            #+#    #+#             */
/*   Updated: 2021/06/25 10:14:21 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** int iterate(int (*func)(t_seat *), t_seat *arg, unsigned int n): 
**
** Apply function func(t_seat *) to each element of array *arr.
** The size of the array must be given by n. The return of the
** function is the the return of func, given that an error might
** occur. In case of sucess, iterate returns zero.
*/

int	iterate(int (*func)(t_seat *), t_seat *arr, unsigned int n)
{
	unsigned int	i;
	int err;

	i = -1;
	err = 0;
	while (++i < n && !err)
		err = func(&arr[i]);
	return (err);
}
