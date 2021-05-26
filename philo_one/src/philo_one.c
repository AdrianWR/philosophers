/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:58:26 by aroque            #+#    #+#             */
/*   Updated: 2021/05/25 22:58:49 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	main(int argc, char *argv[])
{
	t_errcode	err;
	t_params	*params;

	params = NULL;
	err = get_params(argc, argv, params);
	if (err)
	{
		printf("Error\n");
		return (err);
	}
	printf("Finished\n");
	return (0);
}
