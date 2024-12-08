/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:28:20 by mjuicha           #+#    #+#             */
/*   Updated: 2024/12/08 19:17:11 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_(t_data *data)
{
	philo_msg(data, "is eating");
	pthread_mutex_lock(&(data->philo->lock));
	data->last_meal = get_time();
	data->ate++;
	if (data->ate == data->philo->nb_of_meals)
	{
		data->look = 0;
		data->philo->finish--;
	}
	pthread_mutex_unlock(&(data->philo->lock));
	ft_usleep(data->philo->t_eat, data);
}

void	sleep_(t_data *data)
{
	philo_msg(data, "is sleeping");
	ft_usleep(data->philo->t_sleep, data);
}

void	think_(t_data *data)
{
	philo_msg(data, "is thinking");
}
