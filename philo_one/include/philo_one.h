/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:56:49 by aroque            #+#    #+#             */
/*   Updated: 2021/06/05 22:52:17 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef enum e_errcode {
	ERRSYS = 134,
	EINVARG
}	t_errcode;

typedef struct s_params
{
	int	philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	eat_times;
}	t_params;

float		timestamp(struct timeval start);
int			ft_atoi(const char *str);
t_errcode	get_params(int argc, char *argv[], t_params **params);

#endif
