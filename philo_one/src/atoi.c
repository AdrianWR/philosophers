/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:53:48 by aroque            #+#    #+#             */
/*   Updated: 2021/06/05 17:11:17 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char str)
{
	if (str == 0x20 || (str >= 0x09 && str <= 0x0d))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	n;
	int	aux;
	int	signal;

	n = 0;
	aux = 0;
	signal = -1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			signal = 1;
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 - (*str++ - '0');
		if (aux < n)
		{
			if (signal < 0)
				return (-1);
			return (0);
		}
		aux = n;
	}
	return (n * signal);
}
