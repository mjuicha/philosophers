/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:05:42 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/08 20:21:32 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	time;
	long			c_time;

	gettimeofday(&time, NULL);
	c_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (c_time);
}

long	time_(t_philo *philo)
{
	return (get_time() - philo->start_time);
}

void	ft_usleep(long duration, t_data *data)
{
	long	start_time;

	start_time = get_time();
	while (((get_time() - start_time) < duration) && !check_death(data))
		usleep(100);
}
