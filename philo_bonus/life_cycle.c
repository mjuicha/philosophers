/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 05:29:30 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/01 19:56:20 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*death(t_data *data)
{
	while (data->philo->is_died == 0)
	{
		if ((data->last_meal + data->philo->t_die) < get_time())
		{
			sem_wait(data->philo->death);
			sem_wait(data->philo->print);
			data->philo->is_died = 1;
			printf("%ld %d died\n", get_time() - data->philo->start_time,
				data->id);
			exit(1);
		}
		usleep(500);
	}
	return (NULL);
}

void	life_cycle(t_data *data)
{
	while (data->philo->is_died == 0 && data->still_eat == 1)
	{
		sem_wait(data->philo->forks);
		philo_msg(data, "has taken a fork");
		sem_wait(data->philo->forks);
		philo_msg(data, "has taken a fork");
		eat_(data);
		sem_post(data->philo->forks);
		sem_post(data->philo->forks);
		sleep_(data);
		think_(data);
		usleep(100);
	}
}
