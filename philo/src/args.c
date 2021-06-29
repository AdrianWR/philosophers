/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:40:45 by aroque            #+#    #+#             */
/*   Updated: 2021/06/26 15:27:49 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

bool	validate_int(char *elem)
{
	if (!*elem)
		return (true);
	else if (!ft_isdigit(*elem))
		return (false);
	return (validate_int(elem + 1));
}

bool	validate_int_params(int argc, char **argv)
{
	if (!argc)
		return (true);
	if (!validate_int(argv[argc]))
		return (false);
	return (validate_int_params(argc - 1, argv));
}

int	get_table(int argc, char *argv[], t_table *table)
{
	if (argc < 5 || argc > 6)
		return (EINVARG);
	if (!validate_int_params(argc - 1, argv))
		return (EINVARG);
	if (!table)
		return (ERRSYS);
	table->n = ft_atoi(argv[1]);
	table->t_die = ft_atoi(argv[2]);
	table->t_eat = ft_atoi(argv[3]);
	table->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->meals = ft_atoi(argv[5]);
	return (0);
}
