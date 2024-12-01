/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:05:42 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/01 05:44:50 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

long	time_(t_philo *philo)
{
	return (get_time() - philo->start_time);
}

void	ft_usleep(long duration)
{
	long	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < duration)
		usleep(500);
}
