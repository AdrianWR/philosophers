/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:58:26 by aroque            #+#    #+#             */
/*   Updated: 2021/06/05 22:55:46 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int philosophers(t_params *params)
{
    printf("There are %d philosophers\n", params->philosophers);
    return (0);
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
		err = philosophers(params);
	return (err);
}
