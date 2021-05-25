/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:56:49 by aroque            #+#    #+#             */
/*   Updated: 2021/05/24 22:56:54 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

typedef enum e_errcode {
	ERRSYS = 134,
	EINVARG
}	t_errcode;

typedef s_params {
	int philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_die;
	int eat_times;
}	t_params;

float	timestamp(struct timeval start);
int		ft_atoi(const char *str)


#endif
